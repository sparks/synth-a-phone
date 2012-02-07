Help.gui;

s.reboot;

(	
	SynthDef.new("lfo", { arg out = 0, freq = 10, gain = 0.1;
		Out.kr(
			out,
			SinOsc.kr(
				freq,
				0,
				gain
			)
		)
	}).send(s);
	
	SynthDef.new("mm-pulse", {
		arg freq = 300, width = 0.5, mult = 0.2, center = 450, gain = 1, 
		freq_gate1 = 0, width_gate1 = 0, mult_gate1 = 0, center_gate1 = 0, gain_gate1 = 0, 
		freq_gate2 = 0, width_gate2 = 0, mult_gate2 = 0, center_gate2 = 0, gain_gate2 = 0, 
		freq_gate3 = 0, width_gate3 = 0, mult_gate3 = 0, center_gate3 = 0, gain_gate3 = 0, 
		lfo1 = 0, lfo2 = 0, lfo3 = 0;
		Out.ar(
			0, 
			MoogFF.ar(
				Pulse.ar(
					freq+Gate.kr(In.kr(lfo1, 1)*freq, freq_gate1)+Gate.kr(In.kr(lfo2, 1)*freq, freq_gate2)+Gate.kr(In.kr(lfo3, 1)*freq, freq_gate3),
					width+Gate.kr(In.kr(lfo1, 1)*width, width_gate1)+Gate.kr(In.kr(lfo2, 1)*width, width_gate2)+Gate.kr(In.kr(lfo3, 1)*width, width_gate3),
					mult+Gate.kr(In.kr(lfo1, 1)*mult, mult_gate1)+Gate.kr(In.kr(lfo2, 1)*mult, mult_gate2)+Gate.kr(In.kr(lfo3, 1)*mult, mult_gate3)
				),
				center+Gate.kr(In.kr(lfo1, 1)*center, center_gate1)+Gate.kr(In.kr(lfo2, 1)*center, center_gate2)+Gate.kr(In.kr(lfo3, 1)*center, center_gate3),
				gain+Gate.kr(In.kr(lfo1, 1)*gain, gain_gate1)+Gate.kr(In.kr(lfo2, 1)*gain, gain_gate2)+Gate.kr(In.kr(lfo3, 1)*gain, gain_gate3)
			)!2
		) 
	}).send(s);
)
(
	
		
	~emptybus = Bus.control(s, 1);
	~bus1 = Bus.control(s, 1);
	~bus2 = Bus.control(s, 1);
	~bus3 = Bus.control(s, 1);

	~lfo1 = Synth("lfo", ["out", ~bus1.index]);
	~lfo2 = Synth("lfo", ["out", ~bus2.index]);
	~lfo3 = Synth("lfo", ["out", ~bus3.index]);

	~synth = Synth("mm-pulse", ["lfo1", ~bus1.index, "lfo2", ~bus2.index, "lfo3", ~bus3.index]);	
	
	~synth.free;
)

(
	currentEnvironment.clear;
	
	~win = Window("", Rect(1500, 0, 800, 350)); // Window is a subclass of ViewRedirect
	
	~sli = List[];
	
	~kno = List[];
	
	~solo = List[];
	~mute = List[];
	~rec = List[];
	
	8.do{ arg i;
		~sli.add(Slider(~win, Rect(45+(i*97.5), 75, 25, 250)));
	};
	
	8.do{ arg i;
		~kno.add(Knob.new(~win, Rect(34.75+(i*97.5), 10, 48, 48)));
	};
	
	8.do{ arg i;
		~solo.add(Button(~win, Rect(10+(i*97.5), 85, 20, 20)));
		~solo[i].states = [["S", Color.red, Color.black], ["S", Color.black, Color.red]];
		
		~mute.add(Button(~win, Rect(10+(i*97.5), 115, 20, 20)));
		~mute[i].states = [["M", Color.red, Color.black], ["M", Color.black, Color.red]];
		
		~rec.add(Button(~win, Rect(10+(i*97.5), 145, 20, 20)));
		~rec[i].states = [["R", Color.red, Color.black], ["R", Color.black, Color.red]];
	};
	
	~sli[0].action = {arg slider; ~synth.set("freq", slider.value*800+20);};
	~sli[1].action = {arg slider; ~synth.set("width", slider.value);};
	~sli[2].action = {arg slider; ~synth.set("mult", slider.value);};
	~sli[3].action = {arg slider; ~synth.set("center", slider.value*1600+20);};
	~sli[4].action = {arg slider; ~synth.set("gain", slider.value*4);};
	
	~kno[0].action = {arg knob; ~lfo1.set("freq", knob.value*50);};
	~kno[1].action = {arg knob; ~lfo1.set("gain", knob.value);};
	~kno[2].action = {arg knob; ~lfo2.set("freq", knob.value*50);};
	~kno[3].action = {arg knob; ~lfo2.set("gain", knob.value);};
	~kno[4].action = {arg knob; ~lfo3.set("freq", knob.value*50);};
	~kno[5].action = {arg knob; ~lfo3.set("gain", knob.value);};
	
	~solo[0].action = {arg b; ~synth.set("freq_gate1", b.value);};
	~solo[1].action = {arg b; ~synth.set("width_gate1", b.value);};
	~solo[2].action = {arg b; ~synth.set("mult_gate1", b.value);};
	~solo[3].action = {arg b; ~synth.set("center_gate1", b.value);};
	~solo[4].action = {arg b; ~synth.set("gain_gate1", b.value);};
	
	~mute[0].action = {arg b; ~synth.set("freq_gate2", b.value);};
	~mute[1].action = {arg b; ~synth.set("width_gate2", b.value);};
	~mute[2].action = {arg b; ~synth.set("mult_gate2", b.value);};
	~mute[3].action = {arg b; ~synth.set("center_gate2", b.value);};
	~mute[4].action = {arg b; ~synth.set("gain_gate2", b.value);};
	
	~rec[0].action = {arg b; ~synth.set("freq_gate3", b.value);};
	~rec[1].action = {arg b; ~synth.set("width_gate3", b.value);};
	~rec[2].action = {arg b; ~synth.set("mult_gate3", b.value);};
	~rec[3].action = {arg b; ~synth.set("center_gate3", b.value);};
	~rec[4].action = {arg b; ~synth.set("gain_gate3", b.value);};
	
	~win.front();
	
)
	
(
	MIDIClient.init;
	
	MIDIIn.findPort("nanoKONTROL2", "SLIDER/KNOB");
	MIDIIn.findPort("Keystation Mini 32", "Keystation Mini 32");
	
	MIDIIn.connect(0, MIDIIn.findPort("nanoKONTROL2", "SLIDER/KNOB").uid);
	
	MIDIIn.control = { arg src, chan, num, val;
		~kno.do({ arg k, i;
			if((chan == 0) && (num == (i+16))) {
				{k.valueAction = val/127}.defer;
			};
		});
		~sli.do({ arg k, i;
			if((chan == 0) && (num == (i))) {
				{k.valueAction = val/127}.defer;
			};
		});
		~solo.do({ arg k, i;
			if((chan == 0) && (num == (i+32))) {
				if(val == 0) 
					{{k.valueAction = 0}.defer}
					{{k.valueAction = 1}.defer};
			};
		});
		~mute.do({ arg k, i;
			if((chan == 0) && (num == (i+48))) {
				if(val == 0) 
					{{k.valueAction = 0}.defer}
					{{k.valueAction = 1}.defer};
			};
		});
		~rec.do({ arg k, i;
			if((chan == 0) && (num == (i+64))) {
				if(val == 0) 
					{{k.valueAction = 0}.defer}
					{{k.valueAction = 1}.defer};
			};
		});
	};	
)

//MIDIIn.noteOff = { arg src, chan, num, vel; 	[chan,num,vel / 127].postln; };
//MIDIIn.noteOn = { arg src, chan, num, vel; 	[chan,num,vel / 127].postln; };
//MIDIIn.polytouch = { arg src, chan, num, vel; 	[chan,num,vel / 127].postln; };
//MIDIIn.program = { arg src, chan, prog; 		[chan,prog].postln; };
//MIDIIn.touch = { arg src, chan, pressure; 	[chan,pressure].postln; };
//MIDIIn.bend = { arg src, chan, bend; 			[chan,bend - 8192].postln; };
//MIDIIn.sysex = { arg src, sysex; 			sysex.postln; };
//MIDIIn.sysrt = { arg src, chan, val; 			[chan,val].postln; };
//MIDIIn.smpte = { arg src, chan, val; 			[chan,val].postln; };