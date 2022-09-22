#include <iostream>
#include <cstdint>

class SBUS {
public:
	uint8_t MsgPack[25];
	uint16_t ChanelVal[16];

	SBUS(void) {
	}

	SBUS(uint16_t default_val) {
		for (int i = 0; i < sizeof(ChanelVal) / sizeof(ChanelVal[0]); i++) {
			ChanelVal[i] = default_val;
		}
	}

	SBUS(uint8_t channel, uint16_t default_val, uint16_t reset_val = 0) {
		for (int i = 0; i < sizeof(ChanelVal) / sizeof(ChanelVal[0]); i++) {
			if (i < channel) {
				ChanelVal[i] = default_val;
			} else {
				ChanelVal[i] = reset_val;
			}
		}
	}

	~SBUS(void) {
	}

	void Encode(void) {
		MsgPack[0]  = 0x0F; 
		MsgPack[1]  = (uint8_t) ((ChanelVal[0]	& 0x07FF));
		MsgPack[2]  = (uint8_t) ((ChanelVal[0]	& 0x07FF) >> 8	| (ChanelVal[1]	& 0x07FF) << 3);
		MsgPack[3]  = (uint8_t) ((ChanelVal[1]	& 0x07FF) >> 5	| (ChanelVal[2]	& 0x07FF) << 6);
		MsgPack[4]  = (uint8_t) ((ChanelVal[2]	& 0x07FF) >> 2);
		MsgPack[5]  = (uint8_t) ((ChanelVal[2]	& 0x07FF) >> 10	| (ChanelVal[3]	& 0x07FF) << 1);
		MsgPack[6]  = (uint8_t) ((ChanelVal[3]	& 0x07FF) >> 7	| (ChanelVal[4]	& 0x07FF) << 4);
		MsgPack[7]  = (uint8_t) ((ChanelVal[4]	& 0x07FF) >> 4	| (ChanelVal[5]	& 0x07FF) << 7);
		MsgPack[8]  = (uint8_t) ((ChanelVal[5]	& 0x07FF) >> 1);
		MsgPack[9]  = (uint8_t) ((ChanelVal[5]	& 0x07FF) >> 9	| (ChanelVal[6]	& 0x07FF) << 2);
		MsgPack[10] = (uint8_t) ((ChanelVal[6]	& 0x07FF) >> 6	| (ChanelVal[7]	& 0x07FF) << 5);
		MsgPack[11] = (uint8_t) ((ChanelVal[7]	& 0x07FF) >> 3);
		MsgPack[12] = (uint8_t) ((ChanelVal[8]	& 0x07FF));
		MsgPack[13] = (uint8_t) ((ChanelVal[8]	& 0x07FF) >> 8	| (ChanelVal[9]	& 0x07FF) << 3);
		MsgPack[14] = (uint8_t) ((ChanelVal[9]	& 0x07FF) >> 5	| (ChanelVal[10]	& 0x07FF) << 6);  
		MsgPack[15] = (uint8_t) ((ChanelVal[10]	& 0x07FF) >> 2);
		MsgPack[16] = (uint8_t) ((ChanelVal[10]	& 0x07FF) >> 10	| (ChanelVal[11]	& 0x07FF) << 1);
		MsgPack[17] = (uint8_t) ((ChanelVal[11]	& 0x07FF) >> 7	| (ChanelVal[12]	& 0x07FF) << 4);
		MsgPack[18] = (uint8_t) ((ChanelVal[12]	& 0x07FF) >> 4	| (ChanelVal[13]	& 0x07FF) << 7);
		MsgPack[19] = (uint8_t) ((ChanelVal[13]	& 0x07FF) >> 1);
		MsgPack[20] = (uint8_t) ((ChanelVal[13]	& 0x07FF) >> 9	| (ChanelVal[14]	& 0x07FF) << 2);
		MsgPack[21] = (uint8_t) ((ChanelVal[14]	& 0x07FF) >> 6	| (ChanelVal[15]	& 0x07FF) << 5);
		MsgPack[22] = (uint8_t) ((ChanelVal[15]	& 0x07FF) >> 3);
		MsgPack[23] = 0x00;
		MsgPack[24] = 0X00;
	}

	void Decode(void) {
		ChanelVal[0]  = ((MsgPack[1]		| MsgPack[2] << 8)	& 0x07FF);
		ChanelVal[1]  = ((MsgPack[2] >> 3	| MsgPack[3] << 5)	& 0x07FF);
		ChanelVal[2]  = ((MsgPack[3] >> 6	| MsgPack[4] << 2 | MsgPack[5] << 10)	& 0x07FF);
		ChanelVal[3]  = ((MsgPack[5] >> 1	| MsgPack[6] << 7)	& 0x07FF);
		ChanelVal[4]  = ((MsgPack[6] >> 4	| MsgPack[7] <<4)	& 0x07FF);
		ChanelVal[5]  = ((MsgPack[7] >> 7	| MsgPack[8] << 1 | MsgPack[9] << 9)	& 0x07FF);
		ChanelVal[6]  = ((MsgPack[9] >> 2	| MsgPack[10] << 6)	& 0x07FF);
		ChanelVal[7]  = ((MsgPack[10] >> 5	| MsgPack[11] << 3)	& 0x07FF);
		ChanelVal[8]  = ((MsgPack[12]		| MsgPack[13] << 8)	& 0x07FF);
		ChanelVal[9]  = ((MsgPack[13] >> 3	| MsgPack[14]<<5)	& 0x07FF);
		ChanelVal[10] = ((MsgPack[14] >> 6	| MsgPack[15]<<2 | MsgPack[16] << 10)	& 0x07FF);
		ChanelVal[11] = ((MsgPack[16] >> 1	| MsgPack[17]<<7)	& 0x07FF);
		ChanelVal[12] = ((MsgPack[17] >> 4	| MsgPack[18]<<4)	& 0x07FF);
		ChanelVal[13] = ((MsgPack[18] >> 7	| MsgPack[19]<<1 | MsgPack[20]<<9)	& 0x07FF);
		ChanelVal[14] = ((MsgPack[20] >> 2	| MsgPack[21]<<6)	& 0x07FF);
		ChanelVal[15] = ((MsgPack[21] >> 5	| MsgPack[22]<<3)	& 0x07FF);
	}

	void Dump(void) {
		for (int i = 0; i < sizeof(ChanelVal) / sizeof(ChanelVal[0]); i++) {
			std::fprintf(stderr, "[%2d] %d\n", i, ChanelVal[i]);
		}
	}

	void Receive(uint8_t data) {
		static int match = 0, msg_len = 0;
		switch (match) {
		case 0:
			msg_len = 0;
			if (data == 0x0f) {
				MsgPack[0] = 0x0f;
				match = 1;
			}
			break;
		case 1:
			if (msg_len < 23) {
				MsgPack[msg_len + 1] = data;
				msg_len++;
			} else {
				match = 0;
				msg_len = 0;
				if (data == 0x00) {
					MsgPack[24] = 0x00;
					this->Decode();
				}
			}
			break;
		default:
			match = 0;
			msg_len = 0;
			break;
		}
	}

};


int main(int argc, char *argv[])
{
    SBUS sbus(4, 1024);

	sbus.Encode();

	sbus.Decode();

	sbus.Dump();

    return 0;
}
