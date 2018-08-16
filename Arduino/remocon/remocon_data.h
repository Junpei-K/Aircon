#ifndef _REMOCON_DATA_H_
#define _REMOCON_DATA_H_

//--- 運転状況マクロ定義 ---//
// 運転モード
#define COOL 0    // 冷房
#define DRY  1   // 除湿
#define HOT  2   // 暖房
#define WIND 3    // 送風

// 起動/停止
#define START 0    // 起動
#define STOP  1   // 停止

// 電力カット
#define ECO_ON  0    // ON
#define ECO_OFF 1    // OFF

// 風速+運転モード
#define COOL_SPEED1     0    // 風速1冷房
#define COOL_SPEED2     1    // 風速2冷房
#define COOL_SPEED3     2    // 風速3冷房
#define COOL_SPEED4     3    // 風速4冷房
#define COOL_SPEED5     4    // 風速5冷房
#define COOL_SPEED_AUTO 5    // 風速自動冷房

#define DRY_SPEED1     6     // 風速1除湿
#define DRY_SPEED2     7     // 風速2除湿
#define DRY_SPEED_AUTO 8     // 風速自動除湿

#define HOT_SPEED1     9     // 風速1暖房
#define HOT_SPEED2     10    // 風速2暖房
#define HOT_SPEED3     11    // 風速3暖房
#define HOT_SPEED4     12    // 風速4暖房
#define HOT_SPEED5     13    // 風速5暖房
#define HOT_SPEED_AUTO 14    // 風速自動暖房

#define WIND_SPEED1 15    // 風速1送風
#define WIND_SPEED2 16    // 風速2送風
#define WIND_SPEED3 17    // 風速3送風
#define WIND_SPEED4 18    // 風速4送風
#define WIND_SPEED5 19    // 風速5送風

// 室温
#define TEMP_16 0        // 室温16℃
#define TEMP_17 1        // 室温17℃
#define TEMP_18 2        // 室温18℃
#define TEMP_19 3        // 室温19℃
#define TEMP_20 4        // 室温20℃
#define TEMP_21 5        // 室温21℃
#define TEMP_22 6        // 室温22℃
#define TEMP_23 7        // 室温23℃
#define TEMP_24 8        // 室温24℃
#define TEMP_25 9        // 室温25℃
#define TEMP_26 10       // 室温26℃
#define TEMP_27 11       // 室温27℃
#define TEMP_28 12       // 室温28℃
#define TEMP_29 13       // 室温29℃
#define TEMP_30 14       // 室温30℃
#define TEMP_31 15       // 室温31℃
#define TEMP_32 16       // 室温32℃

// 切/入タイマーON/OFF
#define OFF_TIMER_ON  0    // 切タイマーON
#define ON_TIMER_ON_1 1    // 入タイマーON(0.5-4時間)
#define ON_TIMER_ON_2 2    // 入タイマーON(5-8時間)
#define ON_TIMER_ON_3 3    // 入タイマーON(9-12時間)
#define TIMER_OFF     4    // 切/入タイマーOFF

// 切タイマー時間
#define OFF_TIMER_HALF 0        // 切タイマー0.5時間
#define OFF_TIMER_1    1        // 切タイマー1時間
#define OFF_TIMER_2    2        // 切タイマー2時間
#define OFF_TIMER_3    3        // 切タイマー3時間
#define OFF_TIMER_4    4        // 切タイマー4時間
#define OFF_TIMER_5    5        // 切タイマー5時間
#define OFF_TIMER_6    6        // 切タイマー6時間
#define OFF_TIMER_7    7        // 切タイマー7時間
#define OFF_TIMER_8    8        // 切タイマー8時間
#define OFF_TIMER_9    9        // 切タイマー9時間
#define OFF_TIMER_OFF  10       // 切タイマーOFF

// 入タイマー時間
#define ON_TIMER_HALF 0         // 入タイマー0.5時間
#define ON_TIMER_1    1         // 入タイマー1時間
#define ON_TIMER_2    2         // 入タイマー2時間
#define ON_TIMER_3    3         // 入タイマー3時間
#define ON_TIMER_4    4         // 入タイマー4時間
#define ON_TIMER_5    5         // 入タイマー5時間
#define ON_TIMER_6    6         // 入タイマー6時間
#define ON_TIMER_7    7         // 入タイマー7時間
#define ON_TIMER_8    8         // 入タイマー8時間
#define ON_TIMER_9    9         // 入タイマー9時間
#define ON_TIMER_10   10        // 入タイマー10時間
#define ON_TIMER_11   11        // 入タイマー11時間
#define ON_TIMER_12   12        // 入タイマー12時間
#define ON_TIMER_OFF  13        // 入タイマーOFF

// タイマーフラグ
#define TIMER_F_ON  0    // フラグON
#define TIMER_F_OFF 1    // フラグOFF


//--- 内部変数    ---//
// ※送信データ長: 32bit * 53 = 212byte //
static int send_data[53] = {0x01, 0x10, 0x00, 0x40, 0xbf, 0xff, 0x00, 0xcc, 0x33, 0x92,
                            0x6d, 0x00, 0x00, 0x00, 0x93, 0x00, 0xff, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0xff, 0x00, 0xff, 0x80, 0x7f, 0x03, 0xfc, 0x01, 0xfe, 0x88,
                            0x77, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff,
                            0x00, 0xff, 0x00};

static int timer_f;             // タイマーフラグ
static int temp;                // 室温
static int off_timer_time;      // 切タイマー時間
static int on_timer_time;       // 入タイマー時間
static int timer_switch;        // 切/入タイマーON/OFF
static int speed_drive_mode;    // 風速+運転モード
static int power;               // 起動/停止
static int eco;                 // 電力カットON/OFF

#endif // _REMOCON_DATA_H_
