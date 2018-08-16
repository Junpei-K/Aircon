#include "define.h"
#define IR_PIN 12

unsigned long us = micros();

// 送信するデータの初期化
void init_send_data() {
  // 12ブロック:タイマーフラグ
  timer_f = TIMER_F_OFF;

  // 13, 14ブロック:室温
  temp = TEMP_20;

  // 18, 19, 20, 21ブロック：切タイマー時間
  off_timer_time = OFF_TIMER_OFF;

  // 22, 23ブロック：入タイマー時間
  on_timer_time = ON_TIMER_OFF;

  // 24, 25ブロック：切/入タイマーON/OFF
  timer_switch = TIMER_OFF;

  // 26,27ブロック：風速+運転モード
  speed_drive_mode = COOL_SPEED_AUTO;

  // 28, 29ブロック：起動/停止
  power = STOP;

  // 42, 43ブロック：電力カットON/OFF
  eco = ECO_ON;

}

// 送信するデータを作る
void makeData() {
  // タイマーフラグ
  if(timer_f == TIMER_F_OFF) {
    send_data[41] = 0x40;
    send_data[42] = 0xbf;
  } else {
    send_data[41] = 0x00;
    send_data[42] = 0xff;
  }

  // 起動/停止
  if(power == START) {
    send_data[27] = 0xe1;
    send_data[28] = 0x1e;
  } else {
    send_data[27] = 0xf1;
    send_data[28] = 0x0e;
  }

  // 電力カット
  if(eco == ECO_ON) {
    send_data[11] = 0x24;
  } else {
    send_data[11] = 0x22;
  }

  // 室温
  switch(temp) {
    case TEMP_16 :
      send_data[12] = 0x40;
      send_data[13] = 0xbf;
      break;
    case TEMP_17 :
      send_data[12] = 0x44;
      send_data[13] = 0xbb;
      break;
    case TEMP_18 :
      send_data[12] = 0x48;
      send_data[13] = 0xb7;
      break;
    case TEMP_19 :
      send_data[12] = 0x4c;
      send_data[13] = 0xb3;
      break;
    case TEMP_20 :
      send_data[12] = 0x50;
      send_data[13] = 0xaf;
      break;
    case TEMP_21 :
      send_data[12] = 0x54;
      send_data[13] = 0xab;
      break;
    case TEMP_22:
      send_data[12] = 0x58;
      send_data[13] = 0xa7;
      break;
    case TEMP_23 :
      send_data[12] = 0x5c;
      send_data[13] = 0xa3;
      break;
    case TEMP_24 :
      send_data[12] = 0x60;
      send_data[13] = 0x9f;
      break;
    case TEMP_25 :
      send_data[12] = 0x64;
      send_data[13] = 0x9b;
      break;
    case TEMP_26 :
      send_data[12] = 0x68;
      send_data[13] = 0x97;
      break;
    case TEMP_27 :
      send_data[12] = 0x6c;
      send_data[13] = 0x93;
      break;
    case TEMP_28 :
      send_data[12] = 0x70;
      send_data[13] = 0x8f;
      break;
    case TEMP_29 :
      send_data[12] = 0x74;
      send_data[13] = 0x8b;
      break;
    case TEMP_30 :
      send_data[12] = 0x78;
      send_data[13] = 0x87;
      break;
    case TEMP_31 :
      send_data[12] = 0x7c;
      send_data[13] = 0x83;
      break;
    case TEMP_32 :
      send_data[12] = 0x80;
      send_data[13] = 0x7f;
      break;
  }

  // 切タイマー時間
  switch(off_timer_time) {
    case OFF_TIMER_HALF:
      send_data[17] = 0xe0;
      send_data[18] = 0x1f;
      send_data[19] = 0x01;
      send_data[20] = 0xfe;
      break;
    case OFF_TIMER_1:
      send_data[17] = 0xc0;
      send_data[18] = 0x3f;
      send_data[19] = 0x03;
      send_data[20] = 0xfc;
      break;
    case OFF_TIMER_2:
      send_data[17] = 0x80;
      send_data[18] = 0x7f;
      send_data[19] = 0x07;
      send_data[20] = 0xf8;
      break;
    case OFF_TIMER_3:
      send_data[17] = 0x40;
      send_data[18] = 0xbf;
      send_data[19] = 0x0b;
      send_data[20] = 0xf4;
      break;
    case OFF_TIMER_4:
      send_data[17] = 0x00;
      send_data[18] = 0xff;
      send_data[19] = 0x0f;
      send_data[20] = 0xf0;
      break;
    case OFF_TIMER_5:
      send_data[17] = 0xc0;
      send_data[18] = 0x3f;
      send_data[19] = 0x12;
      send_data[20] = 0xed;
      break;
    case OFF_TIMER_6:
      send_data[17] = 0x80;
      send_data[18] = 0x7f;
      send_data[19] = 0x16;
      send_data[20] = 0xe9;
      break;
    case OFF_TIMER_7:
      send_data[17] = 0x40;
      send_data[18] = 0xbf;
      send_data[19] = 0x1a;
      send_data[20] = 0xe5;
      break;
    case OFF_TIMER_8:
      send_data[17] = 0x00;
      send_data[18] = 0xff;
      send_data[19] = 0x1e;
      send_data[20] = 0xe1;
      break;
    case OFF_TIMER_9:
      send_data[17] = 0xc0;
      send_data[18] = 0x3f;
      send_data[19] = 0x21;
      send_data[20] = 0xde;
      break;
    case OFF_TIMER_OFF:
      send_data[17] = 0x00;
      send_data[18] = 0xff;
      send_data[19] = 0x00;
      send_data[20] = 0xff;
      break;
  }

  // 入タイマー時間
  switch(on_timer_time) {
    case ON_TIMER_HALF:
      send_data[21] = 0x1e;
      send_data[22] = 0xe1;
      break;
    case ON_TIMER_1:
      send_data[21] = 0x3c;
      send_data[22] = 0xc3;
      break;
    case ON_TIMER_2:
      send_data[21] = 0x78;
      send_data[22] = 0x87;
      break;
    case ON_TIMER_3:
      send_data[21] = 0xb4;
      send_data[22] = 0x4b;
      break;
    case ON_TIMER_4:
      send_data[21] = 0xf0;
      send_data[22] = 0x0f;
      break;
    case ON_TIMER_5:
      send_data[21] = 0x2c;
      send_data[22] = 0xd3;
      break;
    case ON_TIMER_6:
      send_data[21] = 0x68;
      send_data[22] = 0x97;
      break;
    case ON_TIMER_7:
      send_data[21] = 0xa4;
      send_data[22] = 0x5b;
      break;
    case ON_TIMER_8:
      send_data[21] = 0xe0;
      send_data[22] = 0x1f;
      break;
    case ON_TIMER_9:
      send_data[21] = 0x1c;
      send_data[22] = 0xe3;
      break;
    case ON_TIMER_10:
      send_data[21] = 0x58;
      send_data[22] = 0xa7;
      break;
    case ON_TIMER_11:
      send_data[21] = 0x94;
      send_data[22] = 0x6b;
      break;
    case ON_TIMER_12:
      send_data[21] = 0xd0;
      send_data[22] = 0x2f;
      break;
    case ON_TIMER_OFF:
      send_data[21] = 0x00;
      send_data[22] = 0xff;
      break;
  }

  // 切/入タイマーON/OFF
  switch(timer_switch) {
    case OFF_TIMER_ON:
      send_data[23] = 0x10;
      send_data[24] = 0xef;
      break;
    case ON_TIMER_ON_1:
      send_data[23] = 0x20;
      send_data[24] = 0xdf;
      break;
    case ON_TIMER_ON_2:
      send_data[23] = 0x21;
      send_data[24] = 0xde;
      break;
    case ON_TIMER_ON_3:
      send_data[23] = 0x22;
      send_data[24] = 0xdd;
      break;
    case TIMER_OFF:
      send_data[23] = 0x00;
      send_data[24] = 0xff;
      break;
  }

  // 風速+運転モード
  switch(speed_drive_mode) {
    case COOL_SPEED1:
      send_data[25] = 0x13;
      send_data[26] = 0xec;
      break;
    case COOL_SPEED2:
      send_data[25] = 0x23;
      send_data[26] = 0xdc;
      break;
    case COOL_SPEED3:
      send_data[25] = 0x33;
      send_data[26] = 0xcc;
      break;
    case COOL_SPEED4:
      send_data[25] = 0x43;
      send_data[26] = 0xbc;
      break;
    case COOL_SPEED5:
      send_data[25] = 0x63;
      send_data[26] = 0x9c;
      break;
    case COOL_SPEED_AUTO:
      send_data[25] = 0x53;
      send_data[26] = 0xac;
      break;
    case DRY_SPEED1:
      send_data[25] = 0x15;
      send_data[26] = 0xea;
      break;
    case DRY_SPEED2:
      send_data[25] = 0x25;
      send_data[26] = 0xda;
      break;
    case DRY_SPEED_AUTO:
      send_data[25] = 0x55;
      send_data[26] = 0xaa;
      break;
    case HOT_SPEED1:
      send_data[25] = 0x16;
      send_data[26] = 0xe9;
      break;
    case HOT_SPEED2:
      send_data[25] = 0x26;
      send_data[26] = 0xd9;
      break;
    case HOT_SPEED3:
      send_data[25] = 0x36;
      send_data[26] = 0xc9;
      break;
    case HOT_SPEED4:
      send_data[25] = 0x46;
      send_data[26] = 0xb9;
      break;
    case HOT_SPEED5:
      send_data[25] = 0x66;
      send_data[26] = 0x99;
      break;
    case HOT_SPEED_AUTO:
      send_data[25] = 0x56;
      send_data[26] = 0xa9;
      break;
    case WIND_SPEED1:
      send_data[25] = 0x11;
      send_data[26] = 0xee;
      break;
    case WIND_SPEED2:
      send_data[25] = 0x21;
      send_data[26] = 0xde;
      break;
    case WIND_SPEED3:
      send_data[25] = 0x31;
      send_data[26] = 0xce;
      break;
    case WIND_SPEED4:
      send_data[25] = 0x41;
      send_data[26] = 0xbe;
      break;
    case WIND_SPEED5:
      send_data[25] = 0x61;
      send_data[26] = 0x9e;
      break;
  }
}

// 送信する
void sendSignal(){
  int dataSize = sizeof(send_data) / sizeof(send_data[0]);
  for(int cnt = 0; cnt < dataSize; cnt++) {
    unsigned long len = send_data[cnt]*10; //dataは10us単位でON/OFF時間を記録している
    unsigned long us = micros();
    do {
      digitalWrite(IR_PIN, 1 - (cnt&1));
      delayMicroseconds(8); //キャリア周波数38HzでON/OFFするよう時間調整
      digitalWrite(IR_PIN, 0);
      delayMicroseconds(7);
    } while (long(us + len - micros()) > 0); //送信時間に達するまでループ
  }
}
 
void setup()
{
  delay(100);
  Serial.begin(115200);
  pinMode(IR_PIN, OUTPUT);

  init_send_data();
}

void loop()
{
  // 送信情報を取得する

  
  // 送信するデータを生成する
  makeData();

  // データを送信する
  sendSignal();

  delay(10000);
}
