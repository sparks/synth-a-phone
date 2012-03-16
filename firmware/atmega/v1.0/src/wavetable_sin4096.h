
// Sine wave table of length 4096 from 2047 to -2047

#include <avr/pgmspace.h>

int16_t const sine_lookup[4096] PROGMEM =
{0, 3, 6, 9, 13, 16, 19, 22, 25, 28, 31, 35, 38, 41, 44, 47, 50, 53, 57, 60, 63, 66, 69, 72, 75, 78, 82, 85, 88, 91, 94, 97, 100, 104, 107, 110, 113, 116, 119, 122, 126, 129, 132, 135, 138, 141, 144, 147, 151, 154, 157, 160, 163, 166, 169, 172, 176, 179, 182, 185, 188, 191, 194, 198, 201, 204, 207, 210, 213, 216, 219, 223, 226, 229, 232, 235, 238, 241, 244, 247, 251, 254, 257, 260, 263, 266, 269, 272, 275, 279, 282, 285, 288, 291, 294, 297, 300, 303, 307, 310, 313, 316, 319, 322, 325, 328, 331, 334, 338, 341, 344, 347, 350, 353, 356, 359, 362, 365, 369, 372, 375, 378, 381, 384, 387, 390, 393, 396, 399, 402, 406, 409, 412, 415, 418, 421, 424, 427, 430, 433, 436, 439, 442, 445, 449, 452, 455, 458, 461, 464, 467, 470, 473, 476, 479, 482, 485, 488, 491, 494, 497, 500, 503, 507, 510, 513, 516, 519, 522, 525, 528, 531, 534, 537, 540, 543, 546, 549, 552, 555, 558, 561, 564, 567, 570, 573, 576, 579, 582, 585, 588, 591, 594, 597, 600, 603, 606, 609, 612, 615, 618, 621, 624, 627, 630, 633, 636, 639, 642, 645, 648, 651, 654, 657, 660, 663, 666, 669, 672, 675, 678, 681, 684, 687, 690, 693, 696, 698, 701, 704, 707, 710, 713, 716, 719, 722, 725, 728, 731, 734, 737, 740, 743, 745, 748, 751, 754, 757, 760, 763, 766, 769, 772, 775, 778, 780, 783, 786, 789, 792, 795, 798, 801, 804, 807, 809, 812, 815, 818, 821, 824, 827, 830, 832, 835, 838, 841, 844, 847, 850, 852, 855, 858, 861, 864, 867, 870, 872, 875, 878, 881, 884, 887, 889, 892, 895, 898, 901, 903, 906, 909, 912, 915, 918, 920, 923, 926, 929, 932, 934, 937, 940, 943, 946, 948, 951, 954, 957, 959, 962, 965, 968, 970, 973, 976, 979, 982, 984, 987, 990, 993, 995, 998, 1001, 1003, 1006, 1009, 1012, 1014, 1017, 1020, 1023, 1025, 1028, 1031, 1033, 1036, 1039, 1042, 1044, 1047, 1050, 1052, 1055, 1058, 1060, 1063, 1066, 1068, 1071, 1074, 1077, 1079, 1082, 1085, 1087, 1090, 1092, 1095, 1098, 1100, 1103, 1106, 1108, 1111, 1114, 1116, 1119, 1122, 1124, 1127, 1129, 1132, 1135, 1137, 1140, 1142, 1145, 1148, 1150, 1153, 1155, 1158, 1161, 1163, 1166, 1168, 1171, 1174, 1176, 1179, 1181, 1184, 1186, 1189, 1191, 1194, 1197, 1199, 1202, 1204, 1207, 1209, 1212, 1214, 1217, 1219, 1222, 1224, 1227, 1229, 1232, 1234, 1237, 1239, 1242, 1244, 1247, 1249, 1252, 1254, 1257, 1259, 1262, 1264, 1267, 1269, 1272, 1274, 1277, 1279, 1282, 1284, 1286, 1289, 1291, 1294, 1296, 1299, 1301, 1303, 1306, 1308, 1311, 1313, 1316, 1318, 1320, 1323, 1325, 1328, 1330, 1332, 1335, 1337, 1339, 1342, 1344, 1347, 1349, 1351, 1354, 1356, 1358, 1361, 1363, 1365, 1368, 1370, 1372, 1375, 1377, 1379, 1382, 1384, 1386, 1389, 1391, 1393, 1395, 1398, 1400, 1402, 1405, 1407, 1409, 1411, 1414, 1416, 1418, 1421, 1423, 1425, 1427, 1430, 1432, 1434, 1436, 1439, 1441, 1443, 1445, 1447, 1450, 1452, 1454, 1456, 1459, 1461, 1463, 1465, 1467, 1469, 1472, 1474, 1476, 1478, 1480, 1483, 1485, 1487, 1489, 1491, 1493, 1495, 1498, 1500, 1502, 1504, 1506, 1508, 1510, 1513, 1515, 1517, 1519, 1521, 1523, 1525, 1527, 1529, 1531, 1533, 1536, 1538, 1540, 1542, 1544, 1546, 1548, 1550, 1552, 1554, 1556, 1558, 1560, 1562, 1564, 1566, 1568, 1570, 1572, 1574, 1576, 1578, 1580, 1582, 1584, 1586, 1588, 1590, 1592, 1594, 1596, 1598, 1600, 1602, 1604, 1606, 1608, 1610, 1612, 1614, 1616, 1618, 1620, 1621, 1623, 1625, 1627, 1629, 1631, 1633, 1635, 1637, 1639, 1640, 1642, 1644, 1646, 1648, 1650, 1652, 1653, 1655, 1657, 1659, 1661, 1663, 1665, 1666, 1668, 1670, 1672, 1674, 1675, 1677, 1679, 1681, 1683, 1684, 1686, 1688, 1690, 1691, 1693, 1695, 1697, 1699, 1700, 1702, 1704, 1705, 1707, 1709, 1711, 1712, 1714, 1716, 1718, 1719, 1721, 1723, 1724, 1726, 1728, 1729, 1731, 1733, 1734, 1736, 1738, 1739, 1741, 1743, 1744, 1746, 1748, 1749, 1751, 1753, 1754, 1756, 1757, 1759, 1761, 1762, 1764, 1765, 1767, 1769, 1770, 1772, 1773, 1775, 1776, 1778, 1780, 1781, 1783, 1784, 1786, 1787, 1789, 1790, 1792, 1793, 1795, 1796, 1798, 1799, 1801, 1802, 1804, 1805, 1807, 1808, 1810, 1811, 1813, 1814, 1816, 1817, 1818, 1820, 1821, 1823, 1824, 1826, 1827, 1828, 1830, 1831, 1833, 1834, 1835, 1837, 1838, 1840, 1841, 1842, 1844, 1845, 1846, 1848, 1849, 1850, 1852, 1853, 1854, 1856, 1857, 1858, 1860, 1861, 1862, 1864, 1865, 1866, 1868, 1869, 1870, 1871, 1873, 1874, 1875, 1876, 1878, 1879, 1880, 1881, 1883, 1884, 1885, 1886, 1888, 1889, 1890, 1891, 1892, 1894, 1895, 1896, 1897, 1898, 1899, 1901, 1902, 1903, 1904, 1905, 1906, 1908, 1909, 1910, 1911, 1912, 1913, 1914, 1915, 1917, 1918, 1919, 1920, 1921, 1922, 1923, 1924, 1925, 1926, 1927, 1928, 1929, 1930, 1932, 1933, 1934, 1935, 1936, 1937, 1938, 1939, 1940, 1941, 1942, 1943, 1944, 1945, 1946, 1947, 1948, 1949, 1950, 1950, 1951, 1952, 1953, 1954, 1955, 1956, 1957, 1958, 1959, 1960, 1961, 1962, 1962, 1963, 1964, 1965, 1966, 1967, 1968, 1969, 1969, 1970, 1971, 1972, 1973, 1974, 1975, 1975, 1976, 1977, 1978, 1979, 1979, 1980, 1981, 1982, 1983, 1983, 1984, 1985, 1986, 1986, 1987, 1988, 1989, 1989, 1990, 1991, 1992, 1992, 1993, 1994, 1994, 1995, 1996, 1997, 1997, 1998, 1999, 1999, 2000, 2001, 2001, 2002, 2003, 2003, 2004, 2005, 2005, 2006, 2006, 2007, 2008, 2008, 2009, 2009, 2010, 2011, 2011, 2012, 2012, 2013, 2014, 2014, 2015, 2015, 2016, 2016, 2017, 2017, 2018, 2018, 2019, 2019, 2020, 2021, 2021, 2022, 2022, 2022, 2023, 2023, 2024, 2024, 2025, 2025, 2026, 2026, 2027, 2027, 2028, 2028, 2028, 2029, 2029, 2030, 2030, 2030, 2031, 2031, 2032, 2032, 2032, 2033, 2033, 2033, 2034, 2034, 2035, 2035, 2035, 2036, 2036, 2036, 2037, 2037, 2037, 2037, 2038, 2038, 2038, 2039, 2039, 2039, 2039, 2040, 2040, 2040, 2040, 2041, 2041, 2041, 2041, 2042, 2042, 2042, 2042, 2043, 2043, 2043, 2043, 2043, 2044, 2044, 2044, 2044, 2044, 2044, 2045, 2045, 2045, 2045, 2045, 2045, 2045, 2045, 2046, 2046, 2046, 2046, 2046, 2046, 2046, 2046, 2046, 2046, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2047, 2046, 2046, 2046, 2046, 2046, 2046, 2046, 2046, 2046, 2046, 2045, 2045, 2045, 2045, 2045, 2045, 2045, 2045, 2044, 2044, 2044, 2044, 2044, 2044, 2043, 2043, 2043, 2043, 2043, 2042, 2042, 2042, 2042, 2041, 2041, 2041, 2041, 2040, 2040, 2040, 2040, 2039, 2039, 2039, 2039, 2038, 2038, 2038, 2037, 2037, 2037, 2037, 2036, 2036, 2036, 2035, 2035, 2035, 2034, 2034, 2033, 2033, 2033, 2032, 2032, 2032, 2031, 2031, 2030, 2030, 2030, 2029, 2029, 2028, 2028, 2028, 2027, 2027, 2026, 2026, 2025, 2025, 2024, 2024, 2023, 2023, 2022, 2022, 2022, 2021, 2021, 2020, 2019, 2019, 2018, 2018, 2017, 2017, 2016, 2016, 2015, 2015, 2014, 2014, 2013, 2012, 2012, 2011, 2011, 2010, 2009, 2009, 2008, 2008, 2007, 2006, 2006, 2005, 2005, 2004, 2003, 2003, 2002, 2001, 2001, 2000, 1999, 1999, 1998, 1997, 1997, 1996, 1995, 1994, 1994, 1993, 1992, 1992, 1991, 1990, 1989, 1989, 1988, 1987, 1986, 1986, 1985, 1984, 1983, 1983, 1982, 1981, 1980, 1979, 1979, 1978, 1977, 1976, 1975, 1975, 1974, 1973, 1972, 1971, 1970, 1969, 1969, 1968, 1967, 1966, 1965, 1964, 1963, 1962, 1962, 1961, 1960, 1959, 1958, 1957, 1956, 1955, 1954, 1953, 1952, 1951, 1950, 1950, 1949, 1948, 1947, 1946, 1945, 1944, 1943, 1942, 1941, 1940, 1939, 1938, 1937, 1936, 1935, 1934, 1933, 1932, 1930, 1929, 1928, 1927, 1926, 1925, 1924, 1923, 1922, 1921, 1920, 1919, 1918, 1917, 1915, 1914, 1913, 1912, 1911, 1910, 1909, 1908, 1906, 1905, 1904, 1903, 1902, 1901, 1899, 1898, 1897, 1896, 1895, 1894, 1892, 1891, 1890, 1889, 1888, 1886, 1885, 1884, 1883, 1881, 1880, 1879, 1878, 1876, 1875, 1874, 1873, 1871, 1870, 1869, 1868, 1866, 1865, 1864, 1862, 1861, 1860, 1858, 1857, 1856, 1854, 1853, 1852, 1850, 1849, 1848, 1846, 1845, 1844, 1842, 1841, 1840, 1838, 1837, 1835, 1834, 1833, 1831, 1830, 1828, 1827, 1826, 1824, 1823, 1821, 1820, 1818, 1817, 1816, 1814, 1813, 1811, 1810, 1808, 1807, 1805, 1804, 1802, 1801, 1799, 1798, 1796, 1795, 1793, 1792, 1790, 1789, 1787, 1786, 1784, 1783, 1781, 1780, 1778, 1776, 1775, 1773, 1772, 1770, 1769, 1767, 1765, 1764, 1762, 1761, 1759, 1757, 1756, 1754, 1753, 1751, 1749, 1748, 1746, 1744, 1743, 1741, 1739, 1738, 1736, 1734, 1733, 1731, 1729, 1728, 1726, 1724, 1723, 1721, 1719, 1718, 1716, 1714, 1712, 1711, 1709, 1707, 1705, 1704, 1702, 1700, 1699, 1697, 1695, 1693, 1691, 1690, 1688, 1686, 1684, 1683, 1681, 1679, 1677, 1675, 1674, 1672, 1670, 1668, 1666, 1665, 1663, 1661, 1659, 1657, 1655, 1653, 1652, 1650, 1648, 1646, 1644, 1642, 1640, 1639, 1637, 1635, 1633, 1631, 1629, 1627, 1625, 1623, 1621, 1620, 1618, 1616, 1614, 1612, 1610, 1608, 1606, 1604, 1602, 1600, 1598, 1596, 1594, 1592, 1590, 1588, 1586, 1584, 1582, 1580, 1578, 1576, 1574, 1572, 1570, 1568, 1566, 1564, 1562, 1560, 1558, 1556, 1554, 1552, 1550, 1548, 1546, 1544, 1542, 1540, 1538, 1536, 1533, 1531, 1529, 1527, 1525, 1523, 1521, 1519, 1517, 1515, 1513, 1510, 1508, 1506, 1504, 1502, 1500, 1498, 1495, 1493, 1491, 1489, 1487, 1485, 1483, 1480, 1478, 1476, 1474, 1472, 1469, 1467, 1465, 1463, 1461, 1459, 1456, 1454, 1452, 1450, 1447, 1445, 1443, 1441, 1439, 1436, 1434, 1432, 1430, 1427, 1425, 1423, 1421, 1418, 1416, 1414, 1411, 1409, 1407, 1405, 1402, 1400, 1398, 1395, 1393, 1391, 1389, 1386, 1384, 1382, 1379, 1377, 1375, 1372, 1370, 1368, 1365, 1363, 1361, 1358, 1356, 1354, 1351, 1349, 1347, 1344, 1342, 1339, 1337, 1335, 1332, 1330, 1328, 1325, 1323, 1320, 1318, 1316, 1313, 1311, 1308, 1306, 1303, 1301, 1299, 1296, 1294, 1291, 1289, 1286, 1284, 1282, 1279, 1277, 1274, 1272, 1269, 1267, 1264, 1262, 1259, 1257, 1254, 1252, 1249, 1247, 1244, 1242, 1239, 1237, 1234, 1232, 1229, 1227, 1224, 1222, 1219, 1217, 1214, 1212, 1209, 1207, 1204, 1202, 1199, 1197, 1194, 1191, 1189, 1186, 1184, 1181, 1179, 1176, 1174, 1171, 1168, 1166, 1163, 1161, 1158, 1155, 1153, 1150, 1148, 1145, 1142, 1140, 1137, 1135, 1132, 1129, 1127, 1124, 1122, 1119, 1116, 1114, 1111, 1108, 1106, 1103, 1100, 1098, 1095, 1092, 1090, 1087, 1085, 1082, 1079, 1077, 1074, 1071, 1068, 1066, 1063, 1060, 1058, 1055, 1052, 1050, 1047, 1044, 1042, 1039, 1036, 1033, 1031, 1028, 1025, 1023, 1020, 1017, 1014, 1012, 1009, 1006, 1003, 1001, 998, 995, 993, 990, 987, 984, 982, 979, 976, 973, 970, 968, 965, 962, 959, 957, 954, 951, 948, 946, 943, 940, 937, 934, 932, 929, 926, 923, 920, 918, 915, 912, 909, 906, 903, 901, 898, 895, 892, 889, 887, 884, 881, 878, 875, 872, 870, 867, 864, 861, 858, 855, 852, 850, 847, 844, 841, 838, 835, 832, 830, 827, 824, 821, 818, 815, 812, 809, 807, 804, 801, 798, 795, 792, 789, 786, 783, 780, 778, 775, 772, 769, 766, 763, 760, 757, 754, 751, 748, 745, 743, 740, 737, 734, 731, 728, 725, 722, 719, 716, 713, 710, 707, 704, 701, 698, 696, 693, 690, 687, 684, 681, 678, 675, 672, 669, 666, 663, 660, 657, 654, 651, 648, 645, 642, 639, 636, 633, 630, 627, 624, 621, 618, 615, 612, 609, 606, 603, 600, 597, 594, 591, 588, 585, 582, 579, 576, 573, 570, 567, 564, 561, 558, 555, 552, 549, 546, 543, 540, 537, 534, 531, 528, 525, 522, 519, 516, 513, 510, 507, 503, 500, 497, 494, 491, 488, 485, 482, 479, 476, 473, 470, 467, 464, 461, 458, 455, 452, 449, 445, 442, 439, 436, 433, 430, 427, 424, 421, 418, 415, 412, 409, 406, 402, 399, 396, 393, 390, 387, 384, 381, 378, 375, 372, 369, 365, 362, 359, 356, 353, 350, 347, 344, 341, 338, 334, 331, 328, 325, 322, 319, 316, 313, 310, 307, 303, 300, 297, 294, 291, 288, 285, 282, 279, 275, 272, 269, 266, 263, 260, 257, 254, 251, 247, 244, 241, 238, 235, 232, 229, 226, 223, 219, 216, 213, 210, 207, 204, 201, 198, 194, 191, 188, 185, 182, 179, 176, 172, 169, 166, 163, 160, 157, 154, 151, 147, 144, 141, 138, 135, 132, 129, 126, 122, 119, 116, 113, 110, 107, 104, 100, 97, 94, 91, 88, 85, 82, 78, 75, 72, 69, 66, 63, 60, 57, 53, 50, 47, 44, 41, 38, 35, 31, 28, 25, 22, 19, 16, 13, 9, 6, 3, 0, -3, -6, -9, -13, -16, -19, -22, -25, -28, -31, -35, -38, -41, -44, -47, -50, -53, -57, -60, -63, -66, -69, -72, -75, -78, -82, -85, -88, -91, -94, -97, -100, -104, -107, -110, -113, -116, -119, -122, -126, -129, -132, -135, -138, -141, -144, -147, -151, -154, -157, -160, -163, -166, -169, -172, -176, -179, -182, -185, -188, -191, -194, -198, -201, -204, -207, -210, -213, -216, -219, -223, -226, -229, -232, -235, -238, -241, -244, -247, -251, -254, -257, -260, -263, -266, -269, -272, -275, -279, -282, -285, -288, -291, -294, -297, -300, -303, -307, -310, -313, -316, -319, -322, -325, -328, -331, -334, -338, -341, -344, -347, -350, -353, -356, -359, -362, -365, -369, -372, -375, -378, -381, -384, -387, -390, -393, -396, -399, -402, -406, -409, -412, -415, -418, -421, -424, -427, -430, -433, -436, -439, -442, -445, -449, -452, -455, -458, -461, -464, -467, -470, -473, -476, -479, -482, -485, -488, -491, -494, -497, -500, -503, -507, -510, -513, -516, -519, -522, -525, -528, -531, -534, -537, -540, -543, -546, -549, -552, -555, -558, -561, -564, -567, -570, -573, -576, -579, -582, -585, -588, -591, -594, -597, -600, -603, -606, -609, -612, -615, -618, -621, -624, -627, -630, -633, -636, -639, -642, -645, -648, -651, -654, -657, -660, -663, -666, -669, -672, -675, -678, -681, -684, -687, -690, -693, -696, -698, -701, -704, -707, -710, -713, -716, -719, -722, -725, -728, -731, -734, -737, -740, -743, -745, -748, -751, -754, -757, -760, -763, -766, -769, -772, -775, -778, -780, -783, -786, -789, -792, -795, -798, -801, -804, -807, -809, -812, -815, -818, -821, -824, -827, -830, -832, -835, -838, -841, -844, -847, -850, -852, -855, -858, -861, -864, -867, -870, -872, -875, -878, -881, -884, -887, -889, -892, -895, -898, -901, -903, -906, -909, -912, -915, -918, -920, -923, -926, -929, -932, -934, -937, -940, -943, -946, -948, -951, -954, -957, -959, -962, -965, -968, -970, -973, -976, -979, -982, -984, -987, -990, -993, -995, -998, -1001, -1003, -1006, -1009, -1012, -1014, -1017, -1020, -1023, -1025, -1028, -1031, -1033, -1036, -1039, -1042, -1044, -1047, -1050, -1052, -1055, -1058, -1060, -1063, -1066, -1068, -1071, -1074, -1077, -1079, -1082, -1085, -1087, -1090, -1092, -1095, -1098, -1100, -1103, -1106, -1108, -1111, -1114, -1116, -1119, -1122, -1124, -1127, -1129, -1132, -1135, -1137, -1140, -1142, -1145, -1148, -1150, -1153, -1155, -1158, -1161, -1163, -1166, -1168, -1171, -1174, -1176, -1179, -1181, -1184, -1186, -1189, -1191, -1194, -1197, -1199, -1202, -1204, -1207, -1209, -1212, -1214, -1217, -1219, -1222, -1224, -1227, -1229, -1232, -1234, -1237, -1239, -1242, -1244, -1247, -1249, -1252, -1254, -1257, -1259, -1262, -1264, -1267, -1269, -1272, -1274, -1277, -1279, -1282, -1284, -1286, -1289, -1291, -1294, -1296, -1299, -1301, -1303, -1306, -1308, -1311, -1313, -1316, -1318, -1320, -1323, -1325, -1328, -1330, -1332, -1335, -1337, -1339, -1342, -1344, -1347, -1349, -1351, -1354, -1356, -1358, -1361, -1363, -1365, -1368, -1370, -1372, -1375, -1377, -1379, -1382, -1384, -1386, -1389, -1391, -1393, -1395, -1398, -1400, -1402, -1405, -1407, -1409, -1411, -1414, -1416, -1418, -1421, -1423, -1425, -1427, -1430, -1432, -1434, -1436, -1439, -1441, -1443, -1445, -1447, -1450, -1452, -1454, -1456, -1459, -1461, -1463, -1465, -1467, -1469, -1472, -1474, -1476, -1478, -1480, -1483, -1485, -1487, -1489, -1491, -1493, -1495, -1498, -1500, -1502, -1504, -1506, -1508, -1510, -1513, -1515, -1517, -1519, -1521, -1523, -1525, -1527, -1529, -1531, -1533, -1536, -1538, -1540, -1542, -1544, -1546, -1548, -1550, -1552, -1554, -1556, -1558, -1560, -1562, -1564, -1566, -1568, -1570, -1572, -1574, -1576, -1578, -1580, -1582, -1584, -1586, -1588, -1590, -1592, -1594, -1596, -1598, -1600, -1602, -1604, -1606, -1608, -1610, -1612, -1614, -1616, -1618, -1620, -1621, -1623, -1625, -1627, -1629, -1631, -1633, -1635, -1637, -1639, -1640, -1642, -1644, -1646, -1648, -1650, -1652, -1653, -1655, -1657, -1659, -1661, -1663, -1665, -1666, -1668, -1670, -1672, -1674, -1675, -1677, -1679, -1681, -1683, -1684, -1686, -1688, -1690, -1691, -1693, -1695, -1697, -1699, -1700, -1702, -1704, -1705, -1707, -1709, -1711, -1712, -1714, -1716, -1718, -1719, -1721, -1723, -1724, -1726, -1728, -1729, -1731, -1733, -1734, -1736, -1738, -1739, -1741, -1743, -1744, -1746, -1748, -1749, -1751, -1753, -1754, -1756, -1757, -1759, -1761, -1762, -1764, -1765, -1767, -1769, -1770, -1772, -1773, -1775, -1776, -1778, -1780, -1781, -1783, -1784, -1786, -1787, -1789, -1790, -1792, -1793, -1795, -1796, -1798, -1799, -1801, -1802, -1804, -1805, -1807, -1808, -1810, -1811, -1813, -1814, -1816, -1817, -1818, -1820, -1821, -1823, -1824, -1826, -1827, -1828, -1830, -1831, -1833, -1834, -1835, -1837, -1838, -1840, -1841, -1842, -1844, -1845, -1846, -1848, -1849, -1850, -1852, -1853, -1854, -1856, -1857, -1858, -1860, -1861, -1862, -1864, -1865, -1866, -1868, -1869, -1870, -1871, -1873, -1874, -1875, -1876, -1878, -1879, -1880, -1881, -1883, -1884, -1885, -1886, -1888, -1889, -1890, -1891, -1892, -1894, -1895, -1896, -1897, -1898, -1899, -1901, -1902, -1903, -1904, -1905, -1906, -1908, -1909, -1910, -1911, -1912, -1913, -1914, -1915, -1917, -1918, -1919, -1920, -1921, -1922, -1923, -1924, -1925, -1926, -1927, -1928, -1929, -1930, -1932, -1933, -1934, -1935, -1936, -1937, -1938, -1939, -1940, -1941, -1942, -1943, -1944, -1945, -1946, -1947, -1948, -1949, -1950, -1950, -1951, -1952, -1953, -1954, -1955, -1956, -1957, -1958, -1959, -1960, -1961, -1962, -1962, -1963, -1964, -1965, -1966, -1967, -1968, -1969, -1969, -1970, -1971, -1972, -1973, -1974, -1975, -1975, -1976, -1977, -1978, -1979, -1979, -1980, -1981, -1982, -1983, -1983, -1984, -1985, -1986, -1986, -1987, -1988, -1989, -1989, -1990, -1991, -1992, -1992, -1993, -1994, -1994, -1995, -1996, -1997, -1997, -1998, -1999, -1999, -2000, -2001, -2001, -2002, -2003, -2003, -2004, -2005, -2005, -2006, -2006, -2007, -2008, -2008, -2009, -2009, -2010, -2011, -2011, -2012, -2012, -2013, -2014, -2014, -2015, -2015, -2016, -2016, -2017, -2017, -2018, -2018, -2019, -2019, -2020, -2021, -2021, -2022, -2022, -2022, -2023, -2023, -2024, -2024, -2025, -2025, -2026, -2026, -2027, -2027, -2028, -2028, -2028, -2029, -2029, -2030, -2030, -2030, -2031, -2031, -2032, -2032, -2032, -2033, -2033, -2033, -2034, -2034, -2035, -2035, -2035, -2036, -2036, -2036, -2037, -2037, -2037, -2037, -2038, -2038, -2038, -2039, -2039, -2039, -2039, -2040, -2040, -2040, -2040, -2041, -2041, -2041, -2041, -2042, -2042, -2042, -2042, -2043, -2043, -2043, -2043, -2043, -2044, -2044, -2044, -2044, -2044, -2044, -2045, -2045, -2045, -2045, -2045, -2045, -2045, -2045, -2046, -2046, -2046, -2046, -2046, -2046, -2046, -2046, -2046, -2046, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2047, -2046, -2046, -2046, -2046, -2046, -2046, -2046, -2046, -2046, -2046, -2045, -2045, -2045, -2045, -2045, -2045, -2045, -2045, -2044, -2044, -2044, -2044, -2044, -2044, -2043, -2043, -2043, -2043, -2043, -2042, -2042, -2042, -2042, -2041, -2041, -2041, -2041, -2040, -2040, -2040, -2040, -2039, -2039, -2039, -2039, -2038, -2038, -2038, -2037, -2037, -2037, -2037, -2036, -2036, -2036, -2035, -2035, -2035, -2034, -2034, -2033, -2033, -2033, -2032, -2032, -2032, -2031, -2031, -2030, -2030, -2030, -2029, -2029, -2028, -2028, -2028, -2027, -2027, -2026, -2026, -2025, -2025, -2024, -2024, -2023, -2023, -2022, -2022, -2022, -2021, -2021, -2020, -2019, -2019, -2018, -2018, -2017, -2017, -2016, -2016, -2015, -2015, -2014, -2014, -2013, -2012, -2012, -2011, -2011, -2010, -2009, -2009, -2008, -2008, -2007, -2006, -2006, -2005, -2005, -2004, -2003, -2003, -2002, -2001, -2001, -2000, -1999, -1999, -1998, -1997, -1997, -1996, -1995, -1994, -1994, -1993, -1992, -1992, -1991, -1990, -1989, -1989, -1988, -1987, -1986, -1986, -1985, -1984, -1983, -1983, -1982, -1981, -1980, -1979, -1979, -1978, -1977, -1976, -1975, -1975, -1974, -1973, -1972, -1971, -1970, -1969, -1969, -1968, -1967, -1966, -1965, -1964, -1963, -1962, -1962, -1961, -1960, -1959, -1958, -1957, -1956, -1955, -1954, -1953, -1952, -1951, -1950, -1950, -1949, -1948, -1947, -1946, -1945, -1944, -1943, -1942, -1941, -1940, -1939, -1938, -1937, -1936, -1935, -1934, -1933, -1932, -1930, -1929, -1928, -1927, -1926, -1925, -1924, -1923, -1922, -1921, -1920, -1919, -1918, -1917, -1915, -1914, -1913, -1912, -1911, -1910, -1909, -1908, -1906, -1905, -1904, -1903, -1902, -1901, -1899, -1898, -1897, -1896, -1895, -1894, -1892, -1891, -1890, -1889, -1888, -1886, -1885, -1884, -1883, -1881, -1880, -1879, -1878, -1876, -1875, -1874, -1873, -1871, -1870, -1869, -1868, -1866, -1865, -1864, -1862, -1861, -1860, -1858, -1857, -1856, -1854, -1853, -1852, -1850, -1849, -1848, -1846, -1845, -1844, -1842, -1841, -1840, -1838, -1837, -1835, -1834, -1833, -1831, -1830, -1828, -1827, -1826, -1824, -1823, -1821, -1820, -1818, -1817, -1816, -1814, -1813, -1811, -1810, -1808, -1807, -1805, -1804, -1802, -1801, -1799, -1798, -1796, -1795, -1793, -1792, -1790, -1789, -1787, -1786, -1784, -1783, -1781, -1780, -1778, -1776, -1775, -1773, -1772, -1770, -1769, -1767, -1765, -1764, -1762, -1761, -1759, -1757, -1756, -1754, -1753, -1751, -1749, -1748, -1746, -1744, -1743, -1741, -1739, -1738, -1736, -1734, -1733, -1731, -1729, -1728, -1726, -1724, -1723, -1721, -1719, -1718, -1716, -1714, -1712, -1711, -1709, -1707, -1705, -1704, -1702, -1700, -1699, -1697, -1695, -1693, -1691, -1690, -1688, -1686, -1684, -1683, -1681, -1679, -1677, -1675, -1674, -1672, -1670, -1668, -1666, -1665, -1663, -1661, -1659, -1657, -1655, -1653, -1652, -1650, -1648, -1646, -1644, -1642, -1640, -1639, -1637, -1635, -1633, -1631, -1629, -1627, -1625, -1623, -1621, -1620, -1618, -1616, -1614, -1612, -1610, -1608, -1606, -1604, -1602, -1600, -1598, -1596, -1594, -1592, -1590, -1588, -1586, -1584, -1582, -1580, -1578, -1576, -1574, -1572, -1570, -1568, -1566, -1564, -1562, -1560, -1558, -1556, -1554, -1552, -1550, -1548, -1546, -1544, -1542, -1540, -1538, -1536, -1533, -1531, -1529, -1527, -1525, -1523, -1521, -1519, -1517, -1515, -1513, -1510, -1508, -1506, -1504, -1502, -1500, -1498, -1495, -1493, -1491, -1489, -1487, -1485, -1483, -1480, -1478, -1476, -1474, -1472, -1469, -1467, -1465, -1463, -1461, -1459, -1456, -1454, -1452, -1450, -1447, -1445, -1443, -1441, -1439, -1436, -1434, -1432, -1430, -1427, -1425, -1423, -1421, -1418, -1416, -1414, -1411, -1409, -1407, -1405, -1402, -1400, -1398, -1395, -1393, -1391, -1389, -1386, -1384, -1382, -1379, -1377, -1375, -1372, -1370, -1368, -1365, -1363, -1361, -1358, -1356, -1354, -1351, -1349, -1347, -1344, -1342, -1339, -1337, -1335, -1332, -1330, -1328, -1325, -1323, -1320, -1318, -1316, -1313, -1311, -1308, -1306, -1303, -1301, -1299, -1296, -1294, -1291, -1289, -1286, -1284, -1282, -1279, -1277, -1274, -1272, -1269, -1267, -1264, -1262, -1259, -1257, -1254, -1252, -1249, -1247, -1244, -1242, -1239, -1237, -1234, -1232, -1229, -1227, -1224, -1222, -1219, -1217, -1214, -1212, -1209, -1207, -1204, -1202, -1199, -1197, -1194, -1191, -1189, -1186, -1184, -1181, -1179, -1176, -1174, -1171, -1168, -1166, -1163, -1161, -1158, -1155, -1153, -1150, -1148, -1145, -1142, -1140, -1137, -1135, -1132, -1129, -1127, -1124, -1122, -1119, -1116, -1114, -1111, -1108, -1106, -1103, -1100, -1098, -1095, -1092, -1090, -1087, -1085, -1082, -1079, -1077, -1074, -1071, -1068, -1066, -1063, -1060, -1058, -1055, -1052, -1050, -1047, -1044, -1042, -1039, -1036, -1033, -1031, -1028, -1025, -1023, -1020, -1017, -1014, -1012, -1009, -1006, -1003, -1001, -998, -995, -993, -990, -987, -984, -982, -979, -976, -973, -970, -968, -965, -962, -959, -957, -954, -951, -948, -946, -943, -940, -937, -934, -932, -929, -926, -923, -920, -918, -915, -912, -909, -906, -903, -901, -898, -895, -892, -889, -887, -884, -881, -878, -875, -872, -870, -867, -864, -861, -858, -855, -852, -850, -847, -844, -841, -838, -835, -832, -830, -827, -824, -821, -818, -815, -812, -809, -807, -804, -801, -798, -795, -792, -789, -786, -783, -780, -778, -775, -772, -769, -766, -763, -760, -757, -754, -751, -748, -745, -743, -740, -737, -734, -731, -728, -725, -722, -719, -716, -713, -710, -707, -704, -701, -698, -696, -693, -690, -687, -684, -681, -678, -675, -672, -669, -666, -663, -660, -657, -654, -651, -648, -645, -642, -639, -636, -633, -630, -627, -624, -621, -618, -615, -612, -609, -606, -603, -600, -597, -594, -591, -588, -585, -582, -579, -576, -573, -570, -567, -564, -561, -558, -555, -552, -549, -546, -543, -540, -537, -534, -531, -528, -525, -522, -519, -516, -513, -510, -507, -503, -500, -497, -494, -491, -488, -485, -482, -479, -476, -473, -470, -467, -464, -461, -458, -455, -452, -449, -445, -442, -439, -436, -433, -430, -427, -424, -421, -418, -415, -412, -409, -406, -402, -399, -396, -393, -390, -387, -384, -381, -378, -375, -372, -369, -365, -362, -359, -356, -353, -350, -347, -344, -341, -338, -334, -331, -328, -325, -322, -319, -316, -313, -310, -307, -303, -300, -297, -294, -291, -288, -285, -282, -279, -275, -272, -269, -266, -263, -260, -257, -254, -251, -247, -244, -241, -238, -235, -232, -229, -226, -223, -219, -216, -213, -210, -207, -204, -201, -198, -194, -191, -188, -185, -182, -179, -176, -172, -169, -166, -163, -160, -157, -154, -151, -147, -144, -141, -138, -135, -132, -129, -126, -122, -119, -116, -113, -110, -107, -104, -100, -97, -94, -91, -88, -85, -82, -78, -75, -72, -69, -66, -63, -60, -57, -53, -50, -47, -44, -41, -38, -35, -31, -28, -25, -22, -19, -16, -13, -9, -6, -3};

