//
// Sine lut; 4096 entries, 12 fixeds
//

const int lut_size = 4096; 

const unsigned short sin_table[4096]=
{
	0x0000, 0x0006, 0x000C, 0x0012, 0x0019, 0x001F, 0x0025, 0x002B, 
	0x0032, 0x0038, 0x003E, 0x0045, 0x004B, 0x0051, 0x0057, 0x005E, 
	0x0064, 0x006A, 0x0071, 0x0077, 0x007D, 0x0083, 0x008A, 0x0090, 
	0x0096, 0x009D, 0x00A3, 0x00A9, 0x00AF, 0x00B6, 0x00BC, 0x00C2, 
	0x00C8, 0x00CF, 0x00D5, 0x00DB, 0x00E2, 0x00E8, 0x00EE, 0x00F4, 
	0x00FB, 0x0101, 0x0107, 0x010D, 0x0114, 0x011A, 0x0120, 0x0127, 
	0x012D, 0x0133, 0x0139, 0x0140, 0x0146, 0x014C, 0x0152, 0x0159, 
	0x015F, 0x0165, 0x016B, 0x0172, 0x0178, 0x017E, 0x0184, 0x018B, 
	0x0191, 0x0197, 0x019D, 0x01A4, 0x01AA, 0x01B0, 0x01B6, 0x01BD, 
	0x01C3, 0x01C9, 0x01CF, 0x01D6, 0x01DC, 0x01E2, 0x01E8, 0x01EF, 
	0x01F5, 0x01FB, 0x0201, 0x0208, 0x020E, 0x0214, 0x021A, 0x0221, 
	0x0227, 0x022D, 0x0233, 0x0239, 0x0240, 0x0246, 0x024C, 0x0252, 
	0x0259, 0x025F, 0x0265, 0x026B, 0x0271, 0x0278, 0x027E, 0x0284, 
	0x028A, 0x0290, 0x0297, 0x029D, 0x02A3, 0x02A9, 0x02AF, 0x02B6, 
	0x02BC, 0x02C2, 0x02C8, 0x02CE, 0x02D5, 0x02DB, 0x02E1, 0x02E7, 
	0x02ED, 0x02F3, 0x02FA, 0x0300, 0x0306, 0x030C, 0x0312, 0x0318, 
	0x031F, 0x0325, 0x032B, 0x0331, 0x0337, 0x033D, 0x0344, 0x034A, 
	0x0350, 0x0356, 0x035C, 0x0362, 0x0368, 0x036F, 0x0375, 0x037B, 
	0x0381, 0x0387, 0x038D, 0x0393, 0x0399, 0x03A0, 0x03A6, 0x03AC, 
	0x03B2, 0x03B8, 0x03BE, 0x03C4, 0x03CA, 0x03D0, 0x03D7, 0x03DD, 
	0x03E3, 0x03E9, 0x03EF, 0x03F5, 0x03FB, 0x0401, 0x0407, 0x040D, 
	0x0413, 0x041A, 0x0420, 0x0426, 0x042C, 0x0432, 0x0438, 0x043E, 
	0x0444, 0x044A, 0x0450, 0x0456, 0x045C, 0x0462, 0x0468, 0x046E, 
	0x0474, 0x047A, 0x0480, 0x0486, 0x048C, 0x0492, 0x0498, 0x049E, 
	0x04A5, 0x04AB, 0x04B1, 0x04B7, 0x04BD, 0x04C3, 0x04C9, 0x04CF, 
	0x04D5, 0x04DB, 0x04E0, 0x04E6, 0x04EC, 0x04F2, 0x04F8, 0x04FE, 
	0x0504, 0x050A, 0x0510, 0x0516, 0x051C, 0x0522, 0x0528, 0x052E, 
	0x0534, 0x053A, 0x0540, 0x0546, 0x054C, 0x0552, 0x0558, 0x055D, 
	0x0563, 0x0569, 0x056F, 0x0575, 0x057B, 0x0581, 0x0587, 0x058D, 
	0x0593, 0x0599, 0x059E, 0x05A4, 0x05AA, 0x05B0, 0x05B6, 0x05BC, 
	0x05C2, 0x05C7, 0x05CD, 0x05D3, 0x05D9, 0x05DF, 0x05E5, 0x05EB, 
	0x05F0, 0x05F6, 0x05FC, 0x0602, 0x0608, 0x060E, 0x0613, 0x0619, 
	0x061F, 0x0625, 0x062B, 0x0630, 0x0636, 0x063C, 0x0642, 0x0648, 
	0x064D, 0x0653, 0x0659, 0x065F, 0x0664, 0x066A, 0x0670, 0x0676, 
	0x067B, 0x0681, 0x0687, 0x068D, 0x0692, 0x0698, 0x069E, 0x06A3, 
	0x06A9, 0x06AF, 0x06B5, 0x06BA, 0x06C0, 0x06C6, 0x06CB, 0x06D1, 
	0x06D7, 0x06DC, 0x06E2, 0x06E8, 0x06ED, 0x06F3, 0x06F9, 0x06FE, 
	0x0704, 0x070A, 0x070F, 0x0715, 0x071B, 0x0720, 0x0726, 0x072B, 
	0x0731, 0x0737, 0x073C, 0x0742, 0x0748, 0x074D, 0x0753, 0x0758, 
	0x075E, 0x0763, 0x0769, 0x076F, 0x0774, 0x077A, 0x077F, 0x0785, 
	0x078A, 0x0790, 0x0795, 0x079B, 0x07A0, 0x07A6, 0x07AC, 0x07B1, 
	0x07B7, 0x07BC, 0x07C2, 0x07C7, 0x07CD, 0x07D2, 0x07D7, 0x07DD, 
	0x07E2, 0x07E8, 0x07ED, 0x07F3, 0x07F8, 0x07FE, 0x0803, 0x0809, 
	0x080E, 0x0813, 0x0819, 0x081E, 0x0824, 0x0829, 0x082E, 0x0834, 
	0x0839, 0x083F, 0x0844, 0x0849, 0x084F, 0x0854, 0x085A, 0x085F, 
	0x0864, 0x086A, 0x086F, 0x0874, 0x087A, 0x087F, 0x0884, 0x088A, 
	0x088F, 0x0894, 0x0899, 0x089F, 0x08A4, 0x08A9, 0x08AF, 0x08B4, 
	0x08B9, 0x08BE, 0x08C4, 0x08C9, 0x08CE, 0x08D3, 0x08D9, 0x08DE, 
	0x08E3, 0x08E8, 0x08EE, 0x08F3, 0x08F8, 0x08FD, 0x0902, 0x0908, 
	0x090D, 0x0912, 0x0917, 0x091C, 0x0921, 0x0927, 0x092C, 0x0931, 
	0x0936, 0x093B, 0x0940, 0x0945, 0x094B, 0x0950, 0x0955, 0x095A, 
	0x095F, 0x0964, 0x0969, 0x096E, 0x0973, 0x0978, 0x097D, 0x0982, 
	0x0987, 0x098D, 0x0992, 0x0997, 0x099C, 0x09A1, 0x09A6, 0x09AB, 
	0x09B0, 0x09B5, 0x09BA, 0x09BF, 0x09C4, 0x09C9, 0x09CE, 0x09D3, 
	0x09D7, 0x09DC, 0x09E1, 0x09E6, 0x09EB, 0x09F0, 0x09F5, 0x09FA, 
	0x09FF, 0x0A04, 0x0A09, 0x0A0E, 0x0A12, 0x0A17, 0x0A1C, 0x0A21, 
	0x0A26, 0x0A2B, 0x0A30, 0x0A35, 0x0A39, 0x0A3E, 0x0A43, 0x0A48, 
	0x0A4D, 0x0A51, 0x0A56, 0x0A5B, 0x0A60, 0x0A65, 0x0A69, 0x0A6E, 
	0x0A73, 0x0A78, 0x0A7C, 0x0A81, 0x0A86, 0x0A8B, 0x0A8F, 0x0A94, 
	0x0A99, 0x0A9D, 0x0AA2, 0x0AA7, 0x0AAC, 0x0AB0, 0x0AB5, 0x0ABA, 
	0x0ABE, 0x0AC3, 0x0AC8, 0x0ACC, 0x0AD1, 0x0AD5, 0x0ADA, 0x0ADF, 
	0x0AE3, 0x0AE8, 0x0AEC, 0x0AF1, 0x0AF6, 0x0AFA, 0x0AFF, 0x0B03, 
	0x0B08, 0x0B0C, 0x0B11, 0x0B15, 0x0B1A, 0x0B1F, 0x0B23, 0x0B28, 
	0x0B2C, 0x0B31, 0x0B35, 0x0B3A, 0x0B3E, 0x0B42, 0x0B47, 0x0B4B, 
	0x0B50, 0x0B54, 0x0B59, 0x0B5D, 0x0B62, 0x0B66, 0x0B6A, 0x0B6F, 
	0x0B73, 0x0B78, 0x0B7C, 0x0B80, 0x0B85, 0x0B89, 0x0B8D, 0x0B92, 
	0x0B96, 0x0B9A, 0x0B9F, 0x0BA3, 0x0BA7, 0x0BAC, 0x0BB0, 0x0BB4, 
	0x0BB8, 0x0BBD, 0x0BC1, 0x0BC5, 0x0BCA, 0x0BCE, 0x0BD2, 0x0BD6, 
	0x0BDA, 0x0BDF, 0x0BE3, 0x0BE7, 0x0BEB, 0x0BEF, 0x0BF4, 0x0BF8, 
	0x0BFC, 0x0C00, 0x0C04, 0x0C08, 0x0C0D, 0x0C11, 0x0C15, 0x0C19, 
	0x0C1D, 0x0C21, 0x0C25, 0x0C29, 0x0C2D, 0x0C31, 0x0C36, 0x0C3A, 
	0x0C3E, 0x0C42, 0x0C46, 0x0C4A, 0x0C4E, 0x0C52, 0x0C56, 0x0C5A, 
	0x0C5E, 0x0C62, 0x0C66, 0x0C6A, 0x0C6E, 0x0C72, 0x0C76, 0x0C79, 
	0x0C7D, 0x0C81, 0x0C85, 0x0C89, 0x0C8D, 0x0C91, 0x0C95, 0x0C99, 
	0x0C9D, 0x0CA0, 0x0CA4, 0x0CA8, 0x0CAC, 0x0CB0, 0x0CB4, 0x0CB7, 
	0x0CBB, 0x0CBF, 0x0CC3, 0x0CC7, 0x0CCA, 0x0CCE, 0x0CD2, 0x0CD6, 
	0x0CD9, 0x0CDD, 0x0CE1, 0x0CE5, 0x0CE8, 0x0CEC, 0x0CF0, 0x0CF3, 
	0x0CF7, 0x0CFB, 0x0CFE, 0x0D02, 0x0D06, 0x0D09, 0x0D0D, 0x0D11, 
	0x0D14, 0x0D18, 0x0D1C, 0x0D1F, 0x0D23, 0x0D26, 0x0D2A, 0x0D2D, 
	0x0D31, 0x0D35, 0x0D38, 0x0D3C, 0x0D3F, 0x0D43, 0x0D46, 0x0D4A, 
	0x0D4D, 0x0D51, 0x0D54, 0x0D58, 0x0D5B, 0x0D5F, 0x0D62, 0x0D65, 
	0x0D69, 0x0D6C, 0x0D70, 0x0D73, 0x0D77, 0x0D7A, 0x0D7D, 0x0D81, 
	0x0D84, 0x0D87, 0x0D8B, 0x0D8E, 0x0D91, 0x0D95, 0x0D98, 0x0D9B, 
	0x0D9F, 0x0DA2, 0x0DA5, 0x0DA9, 0x0DAC, 0x0DAF, 0x0DB2, 0x0DB6, 
	0x0DB9, 0x0DBC, 0x0DBF, 0x0DC2, 0x0DC6, 0x0DC9, 0x0DCC, 0x0DCF, 
	0x0DD2, 0x0DD5, 0x0DD9, 0x0DDC, 0x0DDF, 0x0DE2, 0x0DE5, 0x0DE8, 
	0x0DEB, 0x0DEE, 0x0DF2, 0x0DF5, 0x0DF8, 0x0DFB, 0x0DFE, 0x0E01, 
	0x0E04, 0x0E07, 0x0E0A, 0x0E0D, 0x0E10, 0x0E13, 0x0E16, 0x0E19, 
	0x0E1C, 0x0E1F, 0x0E22, 0x0E25, 0x0E28, 0x0E2B, 0x0E2D, 0x0E30, 
	0x0E33, 0x0E36, 0x0E39, 0x0E3C, 0x0E3F, 0x0E42, 0x0E44, 0x0E47, 
	0x0E4A, 0x0E4D, 0x0E50, 0x0E53, 0x0E55, 0x0E58, 0x0E5B, 0x0E5E, 
	0x0E60, 0x0E63, 0x0E66, 0x0E69, 0x0E6B, 0x0E6E, 0x0E71, 0x0E74, 
	0x0E76, 0x0E79, 0x0E7C, 0x0E7E, 0x0E81, 0x0E84, 0x0E86, 0x0E89, 
	0x0E8B, 0x0E8E, 0x0E91, 0x0E93, 0x0E96, 0x0E98, 0x0E9B, 0x0E9E, 
	0x0EA0, 0x0EA3, 0x0EA5, 0x0EA8, 0x0EAA, 0x0EAD, 0x0EAF, 0x0EB2, 
	0x0EB4, 0x0EB7, 0x0EB9, 0x0EBC, 0x0EBE, 0x0EC0, 0x0EC3, 0x0EC5, 
	0x0EC8, 0x0ECA, 0x0ECD, 0x0ECF, 0x0ED1, 0x0ED4, 0x0ED6, 0x0ED8, 
	0x0EDB, 0x0EDD, 0x0EDF, 0x0EE2, 0x0EE4, 0x0EE6, 0x0EE8, 0x0EEB, 
	0x0EED, 0x0EEF, 0x0EF2, 0x0EF4, 0x0EF6, 0x0EF8, 0x0EFA, 0x0EFD, 
	0x0EFF, 0x0F01, 0x0F03, 0x0F05, 0x0F08, 0x0F0A, 0x0F0C, 0x0F0E, 
	0x0F10, 0x0F12, 0x0F14, 0x0F16, 0x0F18, 0x0F1B, 0x0F1D, 0x0F1F, 
	0x0F21, 0x0F23, 0x0F25, 0x0F27, 0x0F29, 0x0F2B, 0x0F2D, 0x0F2F, 
	0x0F31, 0x0F33, 0x0F35, 0x0F37, 0x0F39, 0x0F3B, 0x0F3C, 0x0F3E, 
	0x0F40, 0x0F42, 0x0F44, 0x0F46, 0x0F48, 0x0F4A, 0x0F4B, 0x0F4D, 
	0x0F4F, 0x0F51, 0x0F53, 0x0F55, 0x0F56, 0x0F58, 0x0F5A, 0x0F5C, 
	0x0F5D, 0x0F5F, 0x0F61, 0x0F63, 0x0F64, 0x0F66, 0x0F68, 0x0F69, 
	0x0F6B, 0x0F6D, 0x0F6E, 0x0F70, 0x0F72, 0x0F73, 0x0F75, 0x0F77, 
	0x0F78, 0x0F7A, 0x0F7B, 0x0F7D, 0x0F7F, 0x0F80, 0x0F82, 0x0F83, 
	0x0F85, 0x0F86, 0x0F88, 0x0F89, 0x0F8B, 0x0F8C, 0x0F8E, 0x0F8F, 
	0x0F91, 0x0F92, 0x0F94, 0x0F95, 0x0F96, 0x0F98, 0x0F99, 0x0F9B, 
	0x0F9C, 0x0F9D, 0x0F9F, 0x0FA0, 0x0FA1, 0x0FA3, 0x0FA4, 0x0FA5, 
	0x0FA7, 0x0FA8, 0x0FA9, 0x0FAB, 0x0FAC, 0x0FAD, 0x0FAE, 0x0FB0, 
	0x0FB1, 0x0FB2, 0x0FB3, 0x0FB4, 0x0FB6, 0x0FB7, 0x0FB8, 0x0FB9, 
	0x0FBA, 0x0FBB, 0x0FBD, 0x0FBE, 0x0FBF, 0x0FC0, 0x0FC1, 0x0FC2, 
	0x0FC3, 0x0FC4, 0x0FC5, 0x0FC6, 0x0FC7, 0x0FC8, 0x0FC9, 0x0FCA, 
	0x0FCB, 0x0FCC, 0x0FCD, 0x0FCE, 0x0FCF, 0x0FD0, 0x0FD1, 0x0FD2, 
	0x0FD3, 0x0FD4, 0x0FD5, 0x0FD6, 0x0FD7, 0x0FD8, 0x0FD9, 0x0FD9, 
	0x0FDA, 0x0FDB, 0x0FDC, 0x0FDD, 0x0FDE, 0x0FDE, 0x0FDF, 0x0FE0, 
	0x0FE1, 0x0FE1, 0x0FE2, 0x0FE3, 0x0FE4, 0x0FE4, 0x0FE5, 0x0FE6, 
	0x0FE7, 0x0FE7, 0x0FE8, 0x0FE9, 0x0FE9, 0x0FEA, 0x0FEB, 0x0FEB, 
	0x0FEC, 0x0FEC, 0x0FED, 0x0FEE, 0x0FEE, 0x0FEF, 0x0FEF, 0x0FF0, 
	0x0FF0, 0x0FF1, 0x0FF1, 0x0FF2, 0x0FF2, 0x0FF3, 0x0FF3, 0x0FF4, 
	0x0FF4, 0x0FF5, 0x0FF5, 0x0FF6, 0x0FF6, 0x0FF7, 0x0FF7, 0x0FF7, 
	0x0FF8, 0x0FF8, 0x0FF9, 0x0FF9, 0x0FF9, 0x0FFA, 0x0FFA, 0x0FFA, 
	0x0FFB, 0x0FFB, 0x0FFB, 0x0FFB, 0x0FFC, 0x0FFC, 0x0FFC, 0x0FFC, 
	0x0FFD, 0x0FFD, 0x0FFD, 0x0FFD, 0x0FFE, 0x0FFE, 0x0FFE, 0x0FFE, 
	0x0FFE, 0x0FFE, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 
	0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 
	0x1000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 
	0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFE, 
	0x0FFE, 0x0FFE, 0x0FFE, 0x0FFE, 0x0FFE, 0x0FFD, 0x0FFD, 0x0FFD, 
	0x0FFD, 0x0FFC, 0x0FFC, 0x0FFC, 0x0FFC, 0x0FFB, 0x0FFB, 0x0FFB, 
	0x0FFB, 0x0FFA, 0x0FFA, 0x0FFA, 0x0FF9, 0x0FF9, 0x0FF9, 0x0FF8, 
	0x0FF8, 0x0FF7, 0x0FF7, 0x0FF7, 0x0FF6, 0x0FF6, 0x0FF5, 0x0FF5, 
	0x0FF4, 0x0FF4, 0x0FF3, 0x0FF3, 0x0FF2, 0x0FF2, 0x0FF1, 0x0FF1, 
	0x0FF0, 0x0FF0, 0x0FEF, 0x0FEF, 0x0FEE, 0x0FEE, 0x0FED, 0x0FEC, 
	0x0FEC, 0x0FEB, 0x0FEB, 0x0FEA, 0x0FE9, 0x0FE9, 0x0FE8, 0x0FE7, 
	0x0FE7, 0x0FE6, 0x0FE5, 0x0FE4, 0x0FE4, 0x0FE3, 0x0FE2, 0x0FE1, 
	0x0FE1, 0x0FE0, 0x0FDF, 0x0FDE, 0x0FDE, 0x0FDD, 0x0FDC, 0x0FDB, 
	0x0FDA, 0x0FD9, 0x0FD9, 0x0FD8, 0x0FD7, 0x0FD6, 0x0FD5, 0x0FD4, 
	0x0FD3, 0x0FD2, 0x0FD1, 0x0FD0, 0x0FCF, 0x0FCE, 0x0FCD, 0x0FCC, 
	0x0FCB, 0x0FCA, 0x0FC9, 0x0FC8, 0x0FC7, 0x0FC6, 0x0FC5, 0x0FC4, 
	0x0FC3, 0x0FC2, 0x0FC1, 0x0FC0, 0x0FBF, 0x0FBE, 0x0FBD, 0x0FBB, 
	0x0FBA, 0x0FB9, 0x0FB8, 0x0FB7, 0x0FB6, 0x0FB4, 0x0FB3, 0x0FB2, 
	0x0FB1, 0x0FB0, 0x0FAE, 0x0FAD, 0x0FAC, 0x0FAB, 0x0FA9, 0x0FA8, 
	0x0FA7, 0x0FA5, 0x0FA4, 0x0FA3, 0x0FA1, 0x0FA0, 0x0F9F, 0x0F9D, 
	0x0F9C, 0x0F9B, 0x0F99, 0x0F98, 0x0F96, 0x0F95, 0x0F94, 0x0F92, 
	0x0F91, 0x0F8F, 0x0F8E, 0x0F8C, 0x0F8B, 0x0F89, 0x0F88, 0x0F86, 
	0x0F85, 0x0F83, 0x0F82, 0x0F80, 0x0F7F, 0x0F7D, 0x0F7B, 0x0F7A, 
	0x0F78, 0x0F77, 0x0F75, 0x0F73, 0x0F72, 0x0F70, 0x0F6E, 0x0F6D, 
	0x0F6B, 0x0F69, 0x0F68, 0x0F66, 0x0F64, 0x0F63, 0x0F61, 0x0F5F, 
	0x0F5D, 0x0F5C, 0x0F5A, 0x0F58, 0x0F56, 0x0F55, 0x0F53, 0x0F51, 
	0x0F4F, 0x0F4D, 0x0F4B, 0x0F4A, 0x0F48, 0x0F46, 0x0F44, 0x0F42, 
	0x0F40, 0x0F3E, 0x0F3C, 0x0F3B, 0x0F39, 0x0F37, 0x0F35, 0x0F33, 
	0x0F31, 0x0F2F, 0x0F2D, 0x0F2B, 0x0F29, 0x0F27, 0x0F25, 0x0F23, 
	0x0F21, 0x0F1F, 0x0F1D, 0x0F1B, 0x0F18, 0x0F16, 0x0F14, 0x0F12, 
	0x0F10, 0x0F0E, 0x0F0C, 0x0F0A, 0x0F08, 0x0F05, 0x0F03, 0x0F01, 
	0x0EFF, 0x0EFD, 0x0EFA, 0x0EF8, 0x0EF6, 0x0EF4, 0x0EF2, 0x0EEF, 
	0x0EED, 0x0EEB, 0x0EE8, 0x0EE6, 0x0EE4, 0x0EE2, 0x0EDF, 0x0EDD, 
	0x0EDB, 0x0ED8, 0x0ED6, 0x0ED4, 0x0ED1, 0x0ECF, 0x0ECD, 0x0ECA, 
	0x0EC8, 0x0EC5, 0x0EC3, 0x0EC0, 0x0EBE, 0x0EBC, 0x0EB9, 0x0EB7, 
	0x0EB4, 0x0EB2, 0x0EAF, 0x0EAD, 0x0EAA, 0x0EA8, 0x0EA5, 0x0EA3, 
	0x0EA0, 0x0E9E, 0x0E9B, 0x0E98, 0x0E96, 0x0E93, 0x0E91, 0x0E8E, 
	0x0E8B, 0x0E89, 0x0E86, 0x0E84, 0x0E81, 0x0E7E, 0x0E7C, 0x0E79, 
	0x0E76, 0x0E74, 0x0E71, 0x0E6E, 0x0E6B, 0x0E69, 0x0E66, 0x0E63, 
	0x0E60, 0x0E5E, 0x0E5B, 0x0E58, 0x0E55, 0x0E53, 0x0E50, 0x0E4D, 
	0x0E4A, 0x0E47, 0x0E44, 0x0E42, 0x0E3F, 0x0E3C, 0x0E39, 0x0E36, 
	0x0E33, 0x0E30, 0x0E2D, 0x0E2B, 0x0E28, 0x0E25, 0x0E22, 0x0E1F, 
	0x0E1C, 0x0E19, 0x0E16, 0x0E13, 0x0E10, 0x0E0D, 0x0E0A, 0x0E07, 
	0x0E04, 0x0E01, 0x0DFE, 0x0DFB, 0x0DF8, 0x0DF5, 0x0DF2, 0x0DEE, 
	0x0DEB, 0x0DE8, 0x0DE5, 0x0DE2, 0x0DDF, 0x0DDC, 0x0DD9, 0x0DD5, 
	0x0DD2, 0x0DCF, 0x0DCC, 0x0DC9, 0x0DC6, 0x0DC2, 0x0DBF, 0x0DBC, 
	0x0DB9, 0x0DB6, 0x0DB2, 0x0DAF, 0x0DAC, 0x0DA9, 0x0DA5, 0x0DA2, 
	0x0D9F, 0x0D9B, 0x0D98, 0x0D95, 0x0D91, 0x0D8E, 0x0D8B, 0x0D87, 
	0x0D84, 0x0D81, 0x0D7D, 0x0D7A, 0x0D77, 0x0D73, 0x0D70, 0x0D6C, 
	0x0D69, 0x0D65, 0x0D62, 0x0D5F, 0x0D5B, 0x0D58, 0x0D54, 0x0D51, 
	0x0D4D, 0x0D4A, 0x0D46, 0x0D43, 0x0D3F, 0x0D3C, 0x0D38, 0x0D35, 
	0x0D31, 0x0D2D, 0x0D2A, 0x0D26, 0x0D23, 0x0D1F, 0x0D1C, 0x0D18, 
	0x0D14, 0x0D11, 0x0D0D, 0x0D09, 0x0D06, 0x0D02, 0x0CFE, 0x0CFB, 
	0x0CF7, 0x0CF3, 0x0CF0, 0x0CEC, 0x0CE8, 0x0CE5, 0x0CE1, 0x0CDD, 
	0x0CD9, 0x0CD6, 0x0CD2, 0x0CCE, 0x0CCA, 0x0CC7, 0x0CC3, 0x0CBF, 
	0x0CBB, 0x0CB7, 0x0CB4, 0x0CB0, 0x0CAC, 0x0CA8, 0x0CA4, 0x0CA0, 
	0x0C9D, 0x0C99, 0x0C95, 0x0C91, 0x0C8D, 0x0C89, 0x0C85, 0x0C81, 
	0x0C7D, 0x0C79, 0x0C76, 0x0C72, 0x0C6E, 0x0C6A, 0x0C66, 0x0C62, 
	0x0C5E, 0x0C5A, 0x0C56, 0x0C52, 0x0C4E, 0x0C4A, 0x0C46, 0x0C42, 
	0x0C3E, 0x0C3A, 0x0C36, 0x0C31, 0x0C2D, 0x0C29, 0x0C25, 0x0C21, 
	0x0C1D, 0x0C19, 0x0C15, 0x0C11, 0x0C0D, 0x0C08, 0x0C04, 0x0C00, 
	0x0BFC, 0x0BF8, 0x0BF4, 0x0BEF, 0x0BEB, 0x0BE7, 0x0BE3, 0x0BDF, 
	0x0BDA, 0x0BD6, 0x0BD2, 0x0BCE, 0x0BCA, 0x0BC5, 0x0BC1, 0x0BBD, 
	0x0BB8, 0x0BB4, 0x0BB0, 0x0BAC, 0x0BA7, 0x0BA3, 0x0B9F, 0x0B9A, 
	0x0B96, 0x0B92, 0x0B8D, 0x0B89, 0x0B85, 0x0B80, 0x0B7C, 0x0B78, 
	0x0B73, 0x0B6F, 0x0B6A, 0x0B66, 0x0B62, 0x0B5D, 0x0B59, 0x0B54, 
	0x0B50, 0x0B4B, 0x0B47, 0x0B42, 0x0B3E, 0x0B3A, 0x0B35, 0x0B31, 
	0x0B2C, 0x0B28, 0x0B23, 0x0B1F, 0x0B1A, 0x0B15, 0x0B11, 0x0B0C, 
	0x0B08, 0x0B03, 0x0AFF, 0x0AFA, 0x0AF6, 0x0AF1, 0x0AEC, 0x0AE8, 
	0x0AE3, 0x0ADF, 0x0ADA, 0x0AD5, 0x0AD1, 0x0ACC, 0x0AC8, 0x0AC3, 
	0x0ABE, 0x0ABA, 0x0AB5, 0x0AB0, 0x0AAC, 0x0AA7, 0x0AA2, 0x0A9D, 
	0x0A99, 0x0A94, 0x0A8F, 0x0A8B, 0x0A86, 0x0A81, 0x0A7C, 0x0A78, 
	0x0A73, 0x0A6E, 0x0A69, 0x0A65, 0x0A60, 0x0A5B, 0x0A56, 0x0A51, 
	0x0A4D, 0x0A48, 0x0A43, 0x0A3E, 0x0A39, 0x0A35, 0x0A30, 0x0A2B, 
	0x0A26, 0x0A21, 0x0A1C, 0x0A17, 0x0A12, 0x0A0E, 0x0A09, 0x0A04, 
	0x09FF, 0x09FA, 0x09F5, 0x09F0, 0x09EB, 0x09E6, 0x09E1, 0x09DC, 
	0x09D7, 0x09D3, 0x09CE, 0x09C9, 0x09C4, 0x09BF, 0x09BA, 0x09B5, 
	0x09B0, 0x09AB, 0x09A6, 0x09A1, 0x099C, 0x0997, 0x0992, 0x098D, 
	0x0987, 0x0982, 0x097D, 0x0978, 0x0973, 0x096E, 0x0969, 0x0964, 
	0x095F, 0x095A, 0x0955, 0x0950, 0x094B, 0x0945, 0x0940, 0x093B, 
	0x0936, 0x0931, 0x092C, 0x0927, 0x0921, 0x091C, 0x0917, 0x0912, 
	0x090D, 0x0908, 0x0902, 0x08FD, 0x08F8, 0x08F3, 0x08EE, 0x08E8, 
	0x08E3, 0x08DE, 0x08D9, 0x08D3, 0x08CE, 0x08C9, 0x08C4, 0x08BE, 
	0x08B9, 0x08B4, 0x08AF, 0x08A9, 0x08A4, 0x089F, 0x0899, 0x0894, 
	0x088F, 0x088A, 0x0884, 0x087F, 0x087A, 0x0874, 0x086F, 0x086A, 
	0x0864, 0x085F, 0x085A, 0x0854, 0x084F, 0x0849, 0x0844, 0x083F, 
	0x0839, 0x0834, 0x082E, 0x0829, 0x0824, 0x081E, 0x0819, 0x0813, 
	0x080E, 0x0809, 0x0803, 0x07FE, 0x07F8, 0x07F3, 0x07ED, 0x07E8, 
	0x07E2, 0x07DD, 0x07D7, 0x07D2, 0x07CD, 0x07C7, 0x07C2, 0x07BC, 
	0x07B7, 0x07B1, 0x07AC, 0x07A6, 0x07A0, 0x079B, 0x0795, 0x0790, 
	0x078A, 0x0785, 0x077F, 0x077A, 0x0774, 0x076F, 0x0769, 0x0763, 
	0x075E, 0x0758, 0x0753, 0x074D, 0x0748, 0x0742, 0x073C, 0x0737, 
	0x0731, 0x072B, 0x0726, 0x0720, 0x071B, 0x0715, 0x070F, 0x070A, 
	0x0704, 0x06FE, 0x06F9, 0x06F3, 0x06ED, 0x06E8, 0x06E2, 0x06DC, 
	0x06D7, 0x06D1, 0x06CB, 0x06C6, 0x06C0, 0x06BA, 0x06B5, 0x06AF, 
	0x06A9, 0x06A3, 0x069E, 0x0698, 0x0692, 0x068D, 0x0687, 0x0681, 
	0x067B, 0x0676, 0x0670, 0x066A, 0x0664, 0x065F, 0x0659, 0x0653, 
	0x064D, 0x0648, 0x0642, 0x063C, 0x0636, 0x0630, 0x062B, 0x0625, 
	0x061F, 0x0619, 0x0613, 0x060E, 0x0608, 0x0602, 0x05FC, 0x05F6, 
	0x05F0, 0x05EB, 0x05E5, 0x05DF, 0x05D9, 0x05D3, 0x05CD, 0x05C7, 
	0x05C2, 0x05BC, 0x05B6, 0x05B0, 0x05AA, 0x05A4, 0x059E, 0x0599, 
	0x0593, 0x058D, 0x0587, 0x0581, 0x057B, 0x0575, 0x056F, 0x0569, 
	0x0563, 0x055D, 0x0558, 0x0552, 0x054C, 0x0546, 0x0540, 0x053A, 
	0x0534, 0x052E, 0x0528, 0x0522, 0x051C, 0x0516, 0x0510, 0x050A, 
	0x0504, 0x04FE, 0x04F8, 0x04F2, 0x04EC, 0x04E6, 0x04E0, 0x04DB, 
	0x04D5, 0x04CF, 0x04C9, 0x04C3, 0x04BD, 0x04B7, 0x04B1, 0x04AB, 
	0x04A5, 0x049E, 0x0498, 0x0492, 0x048C, 0x0486, 0x0480, 0x047A, 
	0x0474, 0x046E, 0x0468, 0x0462, 0x045C, 0x0456, 0x0450, 0x044A, 
	0x0444, 0x043E, 0x0438, 0x0432, 0x042C, 0x0426, 0x0420, 0x041A, 
	0x0413, 0x040D, 0x0407, 0x0401, 0x03FB, 0x03F5, 0x03EF, 0x03E9, 
	0x03E3, 0x03DD, 0x03D7, 0x03D0, 0x03CA, 0x03C4, 0x03BE, 0x03B8, 
	0x03B2, 0x03AC, 0x03A6, 0x03A0, 0x0399, 0x0393, 0x038D, 0x0387, 
	0x0381, 0x037B, 0x0375, 0x036F, 0x0368, 0x0362, 0x035C, 0x0356, 
	0x0350, 0x034A, 0x0344, 0x033D, 0x0337, 0x0331, 0x032B, 0x0325, 
	0x031F, 0x0318, 0x0312, 0x030C, 0x0306, 0x0300, 0x02FA, 0x02F3, 
	0x02ED, 0x02E7, 0x02E1, 0x02DB, 0x02D5, 0x02CE, 0x02C8, 0x02C2, 
	0x02BC, 0x02B6, 0x02AF, 0x02A9, 0x02A3, 0x029D, 0x0297, 0x0290, 
	0x028A, 0x0284, 0x027E, 0x0278, 0x0271, 0x026B, 0x0265, 0x025F, 
	0x0259, 0x0252, 0x024C, 0x0246, 0x0240, 0x0239, 0x0233, 0x022D, 
	0x0227, 0x0221, 0x021A, 0x0214, 0x020E, 0x0208, 0x0201, 0x01FB, 
	0x01F5, 0x01EF, 0x01E8, 0x01E2, 0x01DC, 0x01D6, 0x01CF, 0x01C9, 
	0x01C3, 0x01BD, 0x01B6, 0x01B0, 0x01AA, 0x01A4, 0x019D, 0x0197, 
	0x0191, 0x018B, 0x0184, 0x017E, 0x0178, 0x0172, 0x016B, 0x0165, 
	0x015F, 0x0159, 0x0152, 0x014C, 0x0146, 0x0140, 0x0139, 0x0133, 
	0x012D, 0x0127, 0x0120, 0x011A, 0x0114, 0x010D, 0x0107, 0x0101, 
	0x00FB, 0x00F4, 0x00EE, 0x00E8, 0x00E2, 0x00DB, 0x00D5, 0x00CF, 
	0x00C8, 0x00C2, 0x00BC, 0x00B6, 0x00AF, 0x00A9, 0x00A3, 0x009D, 
	0x0096, 0x0090, 0x008A, 0x0083, 0x007D, 0x0077, 0x0071, 0x006A, 
	0x0064, 0x005E, 0x0057, 0x0051, 0x004B, 0x0045, 0x003E, 0x0038, 
	0x0032, 0x002B, 0x0025, 0x001F, 0x0019, 0x0012, 0x000C, 0x0006, 
	0x0000, 0xFFFA, 0xFFF4, 0xFFEE, 0xFFE7, 0xFFE1, 0xFFDB, 0xFFD5, 
	0xFFCE, 0xFFC8, 0xFFC2, 0xFFBB, 0xFFB5, 0xFFAF, 0xFFA9, 0xFFA2, 
	0xFF9C, 0xFF96, 0xFF8F, 0xFF89, 0xFF83, 0xFF7D, 0xFF76, 0xFF70, 
	0xFF6A, 0xFF63, 0xFF5D, 0xFF57, 0xFF51, 0xFF4A, 0xFF44, 0xFF3E, 
	0xFF38, 0xFF31, 0xFF2B, 0xFF25, 0xFF1E, 0xFF18, 0xFF12, 0xFF0C, 
	0xFF05, 0xFEFF, 0xFEF9, 0xFEF3, 0xFEEC, 0xFEE6, 0xFEE0, 0xFED9, 
	0xFED3, 0xFECD, 0xFEC7, 0xFEC0, 0xFEBA, 0xFEB4, 0xFEAE, 0xFEA7, 
	0xFEA1, 0xFE9B, 0xFE95, 0xFE8E, 0xFE88, 0xFE82, 0xFE7C, 0xFE75, 
	0xFE6F, 0xFE69, 0xFE63, 0xFE5C, 0xFE56, 0xFE50, 0xFE4A, 0xFE43, 
	0xFE3D, 0xFE37, 0xFE31, 0xFE2A, 0xFE24, 0xFE1E, 0xFE18, 0xFE11, 
	0xFE0B, 0xFE05, 0xFDFF, 0xFDF8, 0xFDF2, 0xFDEC, 0xFDE6, 0xFDDF, 
	0xFDD9, 0xFDD3, 0xFDCD, 0xFDC7, 0xFDC0, 0xFDBA, 0xFDB4, 0xFDAE, 
	0xFDA7, 0xFDA1, 0xFD9B, 0xFD95, 0xFD8F, 0xFD88, 0xFD82, 0xFD7C, 
	0xFD76, 0xFD70, 0xFD69, 0xFD63, 0xFD5D, 0xFD57, 0xFD51, 0xFD4A, 
	0xFD44, 0xFD3E, 0xFD38, 0xFD32, 0xFD2B, 0xFD25, 0xFD1F, 0xFD19, 
	0xFD13, 0xFD0D, 0xFD06, 0xFD00, 0xFCFA, 0xFCF4, 0xFCEE, 0xFCE8, 
	0xFCE1, 0xFCDB, 0xFCD5, 0xFCCF, 0xFCC9, 0xFCC3, 0xFCBC, 0xFCB6, 
	0xFCB0, 0xFCAA, 0xFCA4, 0xFC9E, 0xFC98, 0xFC91, 0xFC8B, 0xFC85, 
	0xFC7F, 0xFC79, 0xFC73, 0xFC6D, 0xFC67, 0xFC60, 0xFC5A, 0xFC54, 
	0xFC4E, 0xFC48, 0xFC42, 0xFC3C, 0xFC36, 0xFC30, 0xFC29, 0xFC23, 
	0xFC1D, 0xFC17, 0xFC11, 0xFC0B, 0xFC05, 0xFBFF, 0xFBF9, 0xFBF3, 
	0xFBED, 0xFBE6, 0xFBE0, 0xFBDA, 0xFBD4, 0xFBCE, 0xFBC8, 0xFBC2, 
	0xFBBC, 0xFBB6, 0xFBB0, 0xFBAA, 0xFBA4, 0xFB9E, 0xFB98, 0xFB92, 
	0xFB8C, 0xFB86, 0xFB80, 0xFB7A, 0xFB74, 0xFB6E, 0xFB68, 0xFB62, 
	0xFB5B, 0xFB55, 0xFB4F, 0xFB49, 0xFB43, 0xFB3D, 0xFB37, 0xFB31, 
	0xFB2B, 0xFB25, 0xFB20, 0xFB1A, 0xFB14, 0xFB0E, 0xFB08, 0xFB02, 
	0xFAFC, 0xFAF6, 0xFAF0, 0xFAEA, 0xFAE4, 0xFADE, 0xFAD8, 0xFAD2, 
	0xFACC, 0xFAC6, 0xFAC0, 0xFABA, 0xFAB4, 0xFAAE, 0xFAA8, 0xFAA3, 
	0xFA9D, 0xFA97, 0xFA91, 0xFA8B, 0xFA85, 0xFA7F, 0xFA79, 0xFA73, 
	0xFA6D, 0xFA67, 0xFA62, 0xFA5C, 0xFA56, 0xFA50, 0xFA4A, 0xFA44, 
	0xFA3E, 0xFA39, 0xFA33, 0xFA2D, 0xFA27, 0xFA21, 0xFA1B, 0xFA15, 
	0xFA10, 0xFA0A, 0xFA04, 0xF9FE, 0xF9F8, 0xF9F2, 0xF9ED, 0xF9E7, 
	0xF9E1, 0xF9DB, 0xF9D5, 0xF9D0, 0xF9CA, 0xF9C4, 0xF9BE, 0xF9B8, 
	0xF9B3, 0xF9AD, 0xF9A7, 0xF9A1, 0xF99C, 0xF996, 0xF990, 0xF98A, 
	0xF985, 0xF97F, 0xF979, 0xF973, 0xF96E, 0xF968, 0xF962, 0xF95D, 
	0xF957, 0xF951, 0xF94B, 0xF946, 0xF940, 0xF93A, 0xF935, 0xF92F, 
	0xF929, 0xF924, 0xF91E, 0xF918, 0xF913, 0xF90D, 0xF907, 0xF902, 
	0xF8FC, 0xF8F6, 0xF8F1, 0xF8EB, 0xF8E5, 0xF8E0, 0xF8DA, 0xF8D5, 
	0xF8CF, 0xF8C9, 0xF8C4, 0xF8BE, 0xF8B8, 0xF8B3, 0xF8AD, 0xF8A8, 
	0xF8A2, 0xF89D, 0xF897, 0xF891, 0xF88C, 0xF886, 0xF881, 0xF87B, 
	0xF876, 0xF870, 0xF86B, 0xF865, 0xF860, 0xF85A, 0xF854, 0xF84F, 
	0xF849, 0xF844, 0xF83E, 0xF839, 0xF833, 0xF82E, 0xF829, 0xF823, 
	0xF81E, 0xF818, 0xF813, 0xF80D, 0xF808, 0xF802, 0xF7FD, 0xF7F7, 
	0xF7F2, 0xF7ED, 0xF7E7, 0xF7E2, 0xF7DC, 0xF7D7, 0xF7D2, 0xF7CC, 
	0xF7C7, 0xF7C1, 0xF7BC, 0xF7B7, 0xF7B1, 0xF7AC, 0xF7A6, 0xF7A1, 
	0xF79C, 0xF796, 0xF791, 0xF78C, 0xF786, 0xF781, 0xF77C, 0xF776, 
	0xF771, 0xF76C, 0xF767, 0xF761, 0xF75C, 0xF757, 0xF751, 0xF74C, 
	0xF747, 0xF742, 0xF73C, 0xF737, 0xF732, 0xF72D, 0xF727, 0xF722, 
	0xF71D, 0xF718, 0xF712, 0xF70D, 0xF708, 0xF703, 0xF6FE, 0xF6F8, 
	0xF6F3, 0xF6EE, 0xF6E9, 0xF6E4, 0xF6DF, 0xF6D9, 0xF6D4, 0xF6CF, 
	0xF6CA, 0xF6C5, 0xF6C0, 0xF6BB, 0xF6B5, 0xF6B0, 0xF6AB, 0xF6A6, 
	0xF6A1, 0xF69C, 0xF697, 0xF692, 0xF68D, 0xF688, 0xF683, 0xF67E, 
	0xF679, 0xF673, 0xF66E, 0xF669, 0xF664, 0xF65F, 0xF65A, 0xF655, 
	0xF650, 0xF64B, 0xF646, 0xF641, 0xF63C, 0xF637, 0xF632, 0xF62D, 
	0xF629, 0xF624, 0xF61F, 0xF61A, 0xF615, 0xF610, 0xF60B, 0xF606, 
	0xF601, 0xF5FC, 0xF5F7, 0xF5F2, 0xF5EE, 0xF5E9, 0xF5E4, 0xF5DF, 
	0xF5DA, 0xF5D5, 0xF5D0, 0xF5CB, 0xF5C7, 0xF5C2, 0xF5BD, 0xF5B8, 
	0xF5B3, 0xF5AF, 0xF5AA, 0xF5A5, 0xF5A0, 0xF59B, 0xF597, 0xF592, 
	0xF58D, 0xF588, 0xF584, 0xF57F, 0xF57A, 0xF575, 0xF571, 0xF56C, 
	0xF567, 0xF563, 0xF55E, 0xF559, 0xF554, 0xF550, 0xF54B, 0xF546, 
	0xF542, 0xF53D, 0xF538, 0xF534, 0xF52F, 0xF52B, 0xF526, 0xF521, 
	0xF51D, 0xF518, 0xF514, 0xF50F, 0xF50A, 0xF506, 0xF501, 0xF4FD, 
	0xF4F8, 0xF4F4, 0xF4EF, 0xF4EB, 0xF4E6, 0xF4E1, 0xF4DD, 0xF4D8, 
	0xF4D4, 0xF4CF, 0xF4CB, 0xF4C6, 0xF4C2, 0xF4BE, 0xF4B9, 0xF4B5, 
	0xF4B0, 0xF4AC, 0xF4A7, 0xF4A3, 0xF49E, 0xF49A, 0xF496, 0xF491, 
	0xF48D, 0xF488, 0xF484, 0xF480, 0xF47B, 0xF477, 0xF473, 0xF46E, 
	0xF46A, 0xF466, 0xF461, 0xF45D, 0xF459, 0xF454, 0xF450, 0xF44C, 
	0xF448, 0xF443, 0xF43F, 0xF43B, 0xF436, 0xF432, 0xF42E, 0xF42A, 
	0xF426, 0xF421, 0xF41D, 0xF419, 0xF415, 0xF411, 0xF40C, 0xF408, 
	0xF404, 0xF400, 0xF3FC, 0xF3F8, 0xF3F3, 0xF3EF, 0xF3EB, 0xF3E7, 
	0xF3E3, 0xF3DF, 0xF3DB, 0xF3D7, 0xF3D3, 0xF3CF, 0xF3CA, 0xF3C6, 
	0xF3C2, 0xF3BE, 0xF3BA, 0xF3B6, 0xF3B2, 0xF3AE, 0xF3AA, 0xF3A6, 
	0xF3A2, 0xF39E, 0xF39A, 0xF396, 0xF392, 0xF38E, 0xF38A, 0xF387, 
	0xF383, 0xF37F, 0xF37B, 0xF377, 0xF373, 0xF36F, 0xF36B, 0xF367, 
	0xF363, 0xF360, 0xF35C, 0xF358, 0xF354, 0xF350, 0xF34C, 0xF349, 
	0xF345, 0xF341, 0xF33D, 0xF339, 0xF336, 0xF332, 0xF32E, 0xF32A, 
	0xF327, 0xF323, 0xF31F, 0xF31B, 0xF318, 0xF314, 0xF310, 0xF30D, 
	0xF309, 0xF305, 0xF302, 0xF2FE, 0xF2FA, 0xF2F7, 0xF2F3, 0xF2EF, 
	0xF2EC, 0xF2E8, 0xF2E4, 0xF2E1, 0xF2DD, 0xF2DA, 0xF2D6, 0xF2D3, 
	0xF2CF, 0xF2CB, 0xF2C8, 0xF2C4, 0xF2C1, 0xF2BD, 0xF2BA, 0xF2B6, 
	0xF2B3, 0xF2AF, 0xF2AC, 0xF2A8, 0xF2A5, 0xF2A1, 0xF29E, 0xF29B, 
	0xF297, 0xF294, 0xF290, 0xF28D, 0xF289, 0xF286, 0xF283, 0xF27F, 
	0xF27C, 0xF279, 0xF275, 0xF272, 0xF26F, 0xF26B, 0xF268, 0xF265, 
	0xF261, 0xF25E, 0xF25B, 0xF257, 0xF254, 0xF251, 0xF24E, 0xF24A, 
	0xF247, 0xF244, 0xF241, 0xF23E, 0xF23A, 0xF237, 0xF234, 0xF231, 
	0xF22E, 0xF22B, 0xF227, 0xF224, 0xF221, 0xF21E, 0xF21B, 0xF218, 
	0xF215, 0xF212, 0xF20E, 0xF20B, 0xF208, 0xF205, 0xF202, 0xF1FF, 
	0xF1FC, 0xF1F9, 0xF1F6, 0xF1F3, 0xF1F0, 0xF1ED, 0xF1EA, 0xF1E7, 
	0xF1E4, 0xF1E1, 0xF1DE, 0xF1DB, 0xF1D8, 0xF1D5, 0xF1D3, 0xF1D0, 
	0xF1CD, 0xF1CA, 0xF1C7, 0xF1C4, 0xF1C1, 0xF1BE, 0xF1BC, 0xF1B9, 
	0xF1B6, 0xF1B3, 0xF1B0, 0xF1AD, 0xF1AB, 0xF1A8, 0xF1A5, 0xF1A2, 
	0xF1A0, 0xF19D, 0xF19A, 0xF197, 0xF195, 0xF192, 0xF18F, 0xF18C, 
	0xF18A, 0xF187, 0xF184, 0xF182, 0xF17F, 0xF17C, 0xF17A, 0xF177, 
	0xF175, 0xF172, 0xF16F, 0xF16D, 0xF16A, 0xF168, 0xF165, 0xF162, 
	0xF160, 0xF15D, 0xF15B, 0xF158, 0xF156, 0xF153, 0xF151, 0xF14E, 
	0xF14C, 0xF149, 0xF147, 0xF144, 0xF142, 0xF140, 0xF13D, 0xF13B, 
	0xF138, 0xF136, 0xF133, 0xF131, 0xF12F, 0xF12C, 0xF12A, 0xF128, 
	0xF125, 0xF123, 0xF121, 0xF11E, 0xF11C, 0xF11A, 0xF118, 0xF115, 
	0xF113, 0xF111, 0xF10E, 0xF10C, 0xF10A, 0xF108, 0xF106, 0xF103, 
	0xF101, 0xF0FF, 0xF0FD, 0xF0FB, 0xF0F8, 0xF0F6, 0xF0F4, 0xF0F2, 
	0xF0F0, 0xF0EE, 0xF0EC, 0xF0EA, 0xF0E8, 0xF0E5, 0xF0E3, 0xF0E1, 
	0xF0DF, 0xF0DD, 0xF0DB, 0xF0D9, 0xF0D7, 0xF0D5, 0xF0D3, 0xF0D1, 
	0xF0CF, 0xF0CD, 0xF0CB, 0xF0C9, 0xF0C7, 0xF0C5, 0xF0C4, 0xF0C2, 
	0xF0C0, 0xF0BE, 0xF0BC, 0xF0BA, 0xF0B8, 0xF0B6, 0xF0B5, 0xF0B3, 
	0xF0B1, 0xF0AF, 0xF0AD, 0xF0AB, 0xF0AA, 0xF0A8, 0xF0A6, 0xF0A4, 
	0xF0A3, 0xF0A1, 0xF09F, 0xF09D, 0xF09C, 0xF09A, 0xF098, 0xF097, 
	0xF095, 0xF093, 0xF092, 0xF090, 0xF08E, 0xF08D, 0xF08B, 0xF089, 
	0xF088, 0xF086, 0xF085, 0xF083, 0xF081, 0xF080, 0xF07E, 0xF07D, 
	0xF07B, 0xF07A, 0xF078, 0xF077, 0xF075, 0xF074, 0xF072, 0xF071, 
	0xF06F, 0xF06E, 0xF06C, 0xF06B, 0xF06A, 0xF068, 0xF067, 0xF065, 
	0xF064, 0xF063, 0xF061, 0xF060, 0xF05F, 0xF05D, 0xF05C, 0xF05B, 
	0xF059, 0xF058, 0xF057, 0xF055, 0xF054, 0xF053, 0xF052, 0xF050, 
	0xF04F, 0xF04E, 0xF04D, 0xF04C, 0xF04A, 0xF049, 0xF048, 0xF047, 
	0xF046, 0xF045, 0xF043, 0xF042, 0xF041, 0xF040, 0xF03F, 0xF03E, 
	0xF03D, 0xF03C, 0xF03B, 0xF03A, 0xF039, 0xF038, 0xF037, 0xF036, 
	0xF035, 0xF034, 0xF033, 0xF032, 0xF031, 0xF030, 0xF02F, 0xF02E, 
	0xF02D, 0xF02C, 0xF02B, 0xF02A, 0xF029, 0xF028, 0xF027, 0xF027, 
	0xF026, 0xF025, 0xF024, 0xF023, 0xF022, 0xF022, 0xF021, 0xF020, 
	0xF01F, 0xF01F, 0xF01E, 0xF01D, 0xF01C, 0xF01C, 0xF01B, 0xF01A, 
	0xF019, 0xF019, 0xF018, 0xF017, 0xF017, 0xF016, 0xF015, 0xF015, 
	0xF014, 0xF014, 0xF013, 0xF012, 0xF012, 0xF011, 0xF011, 0xF010, 
	0xF010, 0xF00F, 0xF00F, 0xF00E, 0xF00E, 0xF00D, 0xF00D, 0xF00C, 
	0xF00C, 0xF00B, 0xF00B, 0xF00A, 0xF00A, 0xF009, 0xF009, 0xF009, 
	0xF008, 0xF008, 0xF007, 0xF007, 0xF007, 0xF006, 0xF006, 0xF006, 
	0xF005, 0xF005, 0xF005, 0xF005, 0xF004, 0xF004, 0xF004, 0xF004, 
	0xF003, 0xF003, 0xF003, 0xF003, 0xF002, 0xF002, 0xF002, 0xF002, 
	0xF002, 0xF002, 0xF001, 0xF001, 0xF001, 0xF001, 0xF001, 0xF001, 
	0xF001, 0xF001, 0xF001, 0xF001, 0xF001, 0xF001, 0xF001, 0xF001, 
	0xF000, 0xF001, 0xF001, 0xF001, 0xF001, 0xF001, 0xF001, 0xF001, 
	0xF001, 0xF001, 0xF001, 0xF001, 0xF001, 0xF001, 0xF001, 0xF002, 
	0xF002, 0xF002, 0xF002, 0xF002, 0xF002, 0xF003, 0xF003, 0xF003, 
	0xF003, 0xF004, 0xF004, 0xF004, 0xF004, 0xF005, 0xF005, 0xF005, 
	0xF005, 0xF006, 0xF006, 0xF006, 0xF007, 0xF007, 0xF007, 0xF008, 
	0xF008, 0xF009, 0xF009, 0xF009, 0xF00A, 0xF00A, 0xF00B, 0xF00B, 
	0xF00C, 0xF00C, 0xF00D, 0xF00D, 0xF00E, 0xF00E, 0xF00F, 0xF00F, 
	0xF010, 0xF010, 0xF011, 0xF011, 0xF012, 0xF012, 0xF013, 0xF014, 
	0xF014, 0xF015, 0xF015, 0xF016, 0xF017, 0xF017, 0xF018, 0xF019, 
	0xF019, 0xF01A, 0xF01B, 0xF01C, 0xF01C, 0xF01D, 0xF01E, 0xF01F, 
	0xF01F, 0xF020, 0xF021, 0xF022, 0xF022, 0xF023, 0xF024, 0xF025, 
	0xF026, 0xF027, 0xF027, 0xF028, 0xF029, 0xF02A, 0xF02B, 0xF02C, 
	0xF02D, 0xF02E, 0xF02F, 0xF030, 0xF031, 0xF032, 0xF033, 0xF034, 
	0xF035, 0xF036, 0xF037, 0xF038, 0xF039, 0xF03A, 0xF03B, 0xF03C, 
	0xF03D, 0xF03E, 0xF03F, 0xF040, 0xF041, 0xF042, 0xF043, 0xF045, 
	0xF046, 0xF047, 0xF048, 0xF049, 0xF04A, 0xF04C, 0xF04D, 0xF04E, 
	0xF04F, 0xF050, 0xF052, 0xF053, 0xF054, 0xF055, 0xF057, 0xF058, 
	0xF059, 0xF05B, 0xF05C, 0xF05D, 0xF05F, 0xF060, 0xF061, 0xF063, 
	0xF064, 0xF065, 0xF067, 0xF068, 0xF06A, 0xF06B, 0xF06C, 0xF06E, 
	0xF06F, 0xF071, 0xF072, 0xF074, 0xF075, 0xF077, 0xF078, 0xF07A, 
	0xF07B, 0xF07D, 0xF07E, 0xF080, 0xF081, 0xF083, 0xF085, 0xF086, 
	0xF088, 0xF089, 0xF08B, 0xF08D, 0xF08E, 0xF090, 0xF092, 0xF093, 
	0xF095, 0xF097, 0xF098, 0xF09A, 0xF09C, 0xF09D, 0xF09F, 0xF0A1, 
	0xF0A3, 0xF0A4, 0xF0A6, 0xF0A8, 0xF0AA, 0xF0AB, 0xF0AD, 0xF0AF, 
	0xF0B1, 0xF0B3, 0xF0B5, 0xF0B6, 0xF0B8, 0xF0BA, 0xF0BC, 0xF0BE, 
	0xF0C0, 0xF0C2, 0xF0C4, 0xF0C5, 0xF0C7, 0xF0C9, 0xF0CB, 0xF0CD, 
	0xF0CF, 0xF0D1, 0xF0D3, 0xF0D5, 0xF0D7, 0xF0D9, 0xF0DB, 0xF0DD, 
	0xF0DF, 0xF0E1, 0xF0E3, 0xF0E5, 0xF0E8, 0xF0EA, 0xF0EC, 0xF0EE, 
	0xF0F0, 0xF0F2, 0xF0F4, 0xF0F6, 0xF0F8, 0xF0FB, 0xF0FD, 0xF0FF, 
	0xF101, 0xF103, 0xF106, 0xF108, 0xF10A, 0xF10C, 0xF10E, 0xF111, 
	0xF113, 0xF115, 0xF118, 0xF11A, 0xF11C, 0xF11E, 0xF121, 0xF123, 
	0xF125, 0xF128, 0xF12A, 0xF12C, 0xF12F, 0xF131, 0xF133, 0xF136, 
	0xF138, 0xF13B, 0xF13D, 0xF140, 0xF142, 0xF144, 0xF147, 0xF149, 
	0xF14C, 0xF14E, 0xF151, 0xF153, 0xF156, 0xF158, 0xF15B, 0xF15D, 
	0xF160, 0xF162, 0xF165, 0xF168, 0xF16A, 0xF16D, 0xF16F, 0xF172, 
	0xF175, 0xF177, 0xF17A, 0xF17C, 0xF17F, 0xF182, 0xF184, 0xF187, 
	0xF18A, 0xF18C, 0xF18F, 0xF192, 0xF195, 0xF197, 0xF19A, 0xF19D, 
	0xF1A0, 0xF1A2, 0xF1A5, 0xF1A8, 0xF1AB, 0xF1AD, 0xF1B0, 0xF1B3, 
	0xF1B6, 0xF1B9, 0xF1BC, 0xF1BE, 0xF1C1, 0xF1C4, 0xF1C7, 0xF1CA, 
	0xF1CD, 0xF1D0, 0xF1D3, 0xF1D5, 0xF1D8, 0xF1DB, 0xF1DE, 0xF1E1, 
	0xF1E4, 0xF1E7, 0xF1EA, 0xF1ED, 0xF1F0, 0xF1F3, 0xF1F6, 0xF1F9, 
	0xF1FC, 0xF1FF, 0xF202, 0xF205, 0xF208, 0xF20B, 0xF20E, 0xF212, 
	0xF215, 0xF218, 0xF21B, 0xF21E, 0xF221, 0xF224, 0xF227, 0xF22B, 
	0xF22E, 0xF231, 0xF234, 0xF237, 0xF23A, 0xF23E, 0xF241, 0xF244, 
	0xF247, 0xF24A, 0xF24E, 0xF251, 0xF254, 0xF257, 0xF25B, 0xF25E, 
	0xF261, 0xF265, 0xF268, 0xF26B, 0xF26F, 0xF272, 0xF275, 0xF279, 
	0xF27C, 0xF27F, 0xF283, 0xF286, 0xF289, 0xF28D, 0xF290, 0xF294, 
	0xF297, 0xF29B, 0xF29E, 0xF2A1, 0xF2A5, 0xF2A8, 0xF2AC, 0xF2AF, 
	0xF2B3, 0xF2B6, 0xF2BA, 0xF2BD, 0xF2C1, 0xF2C4, 0xF2C8, 0xF2CB, 
	0xF2CF, 0xF2D3, 0xF2D6, 0xF2DA, 0xF2DD, 0xF2E1, 0xF2E4, 0xF2E8, 
	0xF2EC, 0xF2EF, 0xF2F3, 0xF2F7, 0xF2FA, 0xF2FE, 0xF302, 0xF305, 
	0xF309, 0xF30D, 0xF310, 0xF314, 0xF318, 0xF31B, 0xF31F, 0xF323, 
	0xF327, 0xF32A, 0xF32E, 0xF332, 0xF336, 0xF339, 0xF33D, 0xF341, 
	0xF345, 0xF349, 0xF34C, 0xF350, 0xF354, 0xF358, 0xF35C, 0xF360, 
	0xF363, 0xF367, 0xF36B, 0xF36F, 0xF373, 0xF377, 0xF37B, 0xF37F, 
	0xF383, 0xF387, 0xF38A, 0xF38E, 0xF392, 0xF396, 0xF39A, 0xF39E, 
	0xF3A2, 0xF3A6, 0xF3AA, 0xF3AE, 0xF3B2, 0xF3B6, 0xF3BA, 0xF3BE, 
	0xF3C2, 0xF3C6, 0xF3CA, 0xF3CF, 0xF3D3, 0xF3D7, 0xF3DB, 0xF3DF, 
	0xF3E3, 0xF3E7, 0xF3EB, 0xF3EF, 0xF3F3, 0xF3F8, 0xF3FC, 0xF400, 
	0xF404, 0xF408, 0xF40C, 0xF411, 0xF415, 0xF419, 0xF41D, 0xF421, 
	0xF426, 0xF42A, 0xF42E, 0xF432, 0xF436, 0xF43B, 0xF43F, 0xF443, 
	0xF448, 0xF44C, 0xF450, 0xF454, 0xF459, 0xF45D, 0xF461, 0xF466, 
	0xF46A, 0xF46E, 0xF473, 0xF477, 0xF47B, 0xF480, 0xF484, 0xF488, 
	0xF48D, 0xF491, 0xF496, 0xF49A, 0xF49E, 0xF4A3, 0xF4A7, 0xF4AC, 
	0xF4B0, 0xF4B5, 0xF4B9, 0xF4BE, 0xF4C2, 0xF4C6, 0xF4CB, 0xF4CF, 
	0xF4D4, 0xF4D8, 0xF4DD, 0xF4E1, 0xF4E6, 0xF4EB, 0xF4EF, 0xF4F4, 
	0xF4F8, 0xF4FD, 0xF501, 0xF506, 0xF50A, 0xF50F, 0xF514, 0xF518, 
	0xF51D, 0xF521, 0xF526, 0xF52B, 0xF52F, 0xF534, 0xF538, 0xF53D, 
	0xF542, 0xF546, 0xF54B, 0xF550, 0xF554, 0xF559, 0xF55E, 0xF563, 
	0xF567, 0xF56C, 0xF571, 0xF575, 0xF57A, 0xF57F, 0xF584, 0xF588, 
	0xF58D, 0xF592, 0xF597, 0xF59B, 0xF5A0, 0xF5A5, 0xF5AA, 0xF5AF, 
	0xF5B3, 0xF5B8, 0xF5BD, 0xF5C2, 0xF5C7, 0xF5CB, 0xF5D0, 0xF5D5, 
	0xF5DA, 0xF5DF, 0xF5E4, 0xF5E9, 0xF5EE, 0xF5F2, 0xF5F7, 0xF5FC, 
	0xF601, 0xF606, 0xF60B, 0xF610, 0xF615, 0xF61A, 0xF61F, 0xF624, 
	0xF629, 0xF62D, 0xF632, 0xF637, 0xF63C, 0xF641, 0xF646, 0xF64B, 
	0xF650, 0xF655, 0xF65A, 0xF65F, 0xF664, 0xF669, 0xF66E, 0xF673, 
	0xF679, 0xF67E, 0xF683, 0xF688, 0xF68D, 0xF692, 0xF697, 0xF69C, 
	0xF6A1, 0xF6A6, 0xF6AB, 0xF6B0, 0xF6B5, 0xF6BB, 0xF6C0, 0xF6C5, 
	0xF6CA, 0xF6CF, 0xF6D4, 0xF6D9, 0xF6DF, 0xF6E4, 0xF6E9, 0xF6EE, 
	0xF6F3, 0xF6F8, 0xF6FE, 0xF703, 0xF708, 0xF70D, 0xF712, 0xF718, 
	0xF71D, 0xF722, 0xF727, 0xF72D, 0xF732, 0xF737, 0xF73C, 0xF742, 
	0xF747, 0xF74C, 0xF751, 0xF757, 0xF75C, 0xF761, 0xF767, 0xF76C, 
	0xF771, 0xF776, 0xF77C, 0xF781, 0xF786, 0xF78C, 0xF791, 0xF796, 
	0xF79C, 0xF7A1, 0xF7A6, 0xF7AC, 0xF7B1, 0xF7B7, 0xF7BC, 0xF7C1, 
	0xF7C7, 0xF7CC, 0xF7D2, 0xF7D7, 0xF7DC, 0xF7E2, 0xF7E7, 0xF7ED, 
	0xF7F2, 0xF7F7, 0xF7FD, 0xF802, 0xF808, 0xF80D, 0xF813, 0xF818, 
	0xF81E, 0xF823, 0xF829, 0xF82E, 0xF833, 0xF839, 0xF83E, 0xF844, 
	0xF849, 0xF84F, 0xF854, 0xF85A, 0xF860, 0xF865, 0xF86B, 0xF870, 
	0xF876, 0xF87B, 0xF881, 0xF886, 0xF88C, 0xF891, 0xF897, 0xF89D, 
	0xF8A2, 0xF8A8, 0xF8AD, 0xF8B3, 0xF8B8, 0xF8BE, 0xF8C4, 0xF8C9, 
	0xF8CF, 0xF8D5, 0xF8DA, 0xF8E0, 0xF8E5, 0xF8EB, 0xF8F1, 0xF8F6, 
	0xF8FC, 0xF902, 0xF907, 0xF90D, 0xF913, 0xF918, 0xF91E, 0xF924, 
	0xF929, 0xF92F, 0xF935, 0xF93A, 0xF940, 0xF946, 0xF94B, 0xF951, 
	0xF957, 0xF95D, 0xF962, 0xF968, 0xF96E, 0xF973, 0xF979, 0xF97F, 
	0xF985, 0xF98A, 0xF990, 0xF996, 0xF99C, 0xF9A1, 0xF9A7, 0xF9AD, 
	0xF9B3, 0xF9B8, 0xF9BE, 0xF9C4, 0xF9CA, 0xF9D0, 0xF9D5, 0xF9DB, 
	0xF9E1, 0xF9E7, 0xF9ED, 0xF9F2, 0xF9F8, 0xF9FE, 0xFA04, 0xFA0A, 
	0xFA10, 0xFA15, 0xFA1B, 0xFA21, 0xFA27, 0xFA2D, 0xFA33, 0xFA39, 
	0xFA3E, 0xFA44, 0xFA4A, 0xFA50, 0xFA56, 0xFA5C, 0xFA62, 0xFA67, 
	0xFA6D, 0xFA73, 0xFA79, 0xFA7F, 0xFA85, 0xFA8B, 0xFA91, 0xFA97, 
	0xFA9D, 0xFAA3, 0xFAA8, 0xFAAE, 0xFAB4, 0xFABA, 0xFAC0, 0xFAC6, 
	0xFACC, 0xFAD2, 0xFAD8, 0xFADE, 0xFAE4, 0xFAEA, 0xFAF0, 0xFAF6, 
	0xFAFC, 0xFB02, 0xFB08, 0xFB0E, 0xFB14, 0xFB1A, 0xFB20, 0xFB25, 
	0xFB2B, 0xFB31, 0xFB37, 0xFB3D, 0xFB43, 0xFB49, 0xFB4F, 0xFB55, 
	0xFB5B, 0xFB62, 0xFB68, 0xFB6E, 0xFB74, 0xFB7A, 0xFB80, 0xFB86, 
	0xFB8C, 0xFB92, 0xFB98, 0xFB9E, 0xFBA4, 0xFBAA, 0xFBB0, 0xFBB6, 
	0xFBBC, 0xFBC2, 0xFBC8, 0xFBCE, 0xFBD4, 0xFBDA, 0xFBE0, 0xFBE6, 
	0xFBED, 0xFBF3, 0xFBF9, 0xFBFF, 0xFC05, 0xFC0B, 0xFC11, 0xFC17, 
	0xFC1D, 0xFC23, 0xFC29, 0xFC30, 0xFC36, 0xFC3C, 0xFC42, 0xFC48, 
	0xFC4E, 0xFC54, 0xFC5A, 0xFC60, 0xFC67, 0xFC6D, 0xFC73, 0xFC79, 
	0xFC7F, 0xFC85, 0xFC8B, 0xFC91, 0xFC98, 0xFC9E, 0xFCA4, 0xFCAA, 
	0xFCB0, 0xFCB6, 0xFCBC, 0xFCC3, 0xFCC9, 0xFCCF, 0xFCD5, 0xFCDB, 
	0xFCE1, 0xFCE8, 0xFCEE, 0xFCF4, 0xFCFA, 0xFD00, 0xFD06, 0xFD0D, 
	0xFD13, 0xFD19, 0xFD1F, 0xFD25, 0xFD2B, 0xFD32, 0xFD38, 0xFD3E, 
	0xFD44, 0xFD4A, 0xFD51, 0xFD57, 0xFD5D, 0xFD63, 0xFD69, 0xFD70, 
	0xFD76, 0xFD7C, 0xFD82, 0xFD88, 0xFD8F, 0xFD95, 0xFD9B, 0xFDA1, 
	0xFDA7, 0xFDAE, 0xFDB4, 0xFDBA, 0xFDC0, 0xFDC7, 0xFDCD, 0xFDD3, 
	0xFDD9, 0xFDDF, 0xFDE6, 0xFDEC, 0xFDF2, 0xFDF8, 0xFDFF, 0xFE05, 
	0xFE0B, 0xFE11, 0xFE18, 0xFE1E, 0xFE24, 0xFE2A, 0xFE31, 0xFE37, 
	0xFE3D, 0xFE43, 0xFE4A, 0xFE50, 0xFE56, 0xFE5C, 0xFE63, 0xFE69, 
	0xFE6F, 0xFE75, 0xFE7C, 0xFE82, 0xFE88, 0xFE8E, 0xFE95, 0xFE9B, 
	0xFEA1, 0xFEA7, 0xFEAE, 0xFEB4, 0xFEBA, 0xFEC0, 0xFEC7, 0xFECD, 
	0xFED3, 0xFED9, 0xFEE0, 0xFEE6, 0xFEEC, 0xFEF3, 0xFEF9, 0xFEFF, 
	0xFF05, 0xFF0C, 0xFF12, 0xFF18, 0xFF1E, 0xFF25, 0xFF2B, 0xFF31, 
	0xFF38, 0xFF3E, 0xFF44, 0xFF4A, 0xFF51, 0xFF57, 0xFF5D, 0xFF63, 
	0xFF6A, 0xFF70, 0xFF76, 0xFF7D, 0xFF83, 0xFF89, 0xFF8F, 0xFF96, 
	0xFF9C, 0xFFA2, 0xFFA9, 0xFFAF, 0xFFB5, 0xFFBB, 0xFFC2, 0xFFC8, 
	0xFFCE, 0xFFD5, 0xFFDB, 0xFFE1, 0xFFE7, 0xFFEE, 0xFFF4, 0xFFFA, 
};