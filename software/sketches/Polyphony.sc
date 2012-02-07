Help.gui;

s.reboot;

(
	SynthDef("env-test", { arg out = 0, freq = 440, bend = 0, gate = 0, mult = 0.75; 
		var z;
		z = EnvGen.kr(Env.adsr, gate) * Saw.ar(freq+bend*freq/5, mult);
		Out.ar(out, z!2)
	}).send(s);
	
	~synth = Array.newClear(128);
	
	128.do{ arg i;
		~synth[i] = Synth("env-test", ["freq", i.midicps]);
	};
	
	128.do{ arg i;
		~synth[i].free;
	};
)

(
	MIDIClient.init;
	
	MIDIIn.findPort("Keystation Mini 32", "Keystation Mini 32");
	
	MIDIIn.connect(0, MIDIIn.findPort("Keystation Mini 32", "Keystation Mini 32").uid);
	
	MIDIIn.noteOn = { arg src, chan, num, vel; ~synth[num].set("gate", 1, "freq", num.midicps); };
	MIDIIn.noteOff = { arg src, chan, num, vel; ~synth[num].set("gate", 0); };

	MIDIIn.control = { arg src, chan, num, val; 
		128.do{ arg i;
			~synth[i].set("mult", val/127);
		}; 
	};
	MIDIIn.bend = { arg src, chan, bend;
		128.do{ arg i;
			~synth[i].set("freq", (bend-8192)/8192);
		};
	};
)

//x.get(\freq, { arg value; ("freq is now:" + value + "Hz").postln; });
