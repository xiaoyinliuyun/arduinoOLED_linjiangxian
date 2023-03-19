/**********************************************************************
  程序名称/Program name     : hans_display
  团队/Team                 : 太极创客团队 / Taichi-Maker (www.taichi-maker.com)
  作者/Author               : Dapenson
  日期/Date（YYYYMMDD）     : 2020/07/01
  程序目的/Purpose          :
  使用OLED0.96 IIC 12864显示汉字
  -----------------------------------------------------------------------
  修订历史/Revision History
  日期/Date    作者/Author      参考号/Ref    修订说明/Revision Description
  -----------------------------------------------------------------------
  其它说明：
***********************************************************************/

// 引入IIC通讯所需的Wire库文件
// 教程参考http://www.taichi-maker.com/homepage/reference-index/arduino-library-index/wire-library/
#include <Wire.h>

#include "text.h"
#include "text1.h"

// 引入驱动OLED0.96所需的库
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // 设置OLED宽度,单位:像素
#define SCREEN_HEIGHT 64  // 设置OLED高度,单位:像素

// 自定义重置引脚,虽然教程未使用,但却是Adafruit_SSD1306库文件所必需的
#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

float currentLine = -9;

void setup() {
  Serial.begin(9600);
  // 初始化OLED并设置其IIC地址为 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {
  hans_display_0();
  // hans_display_1();
}

void hans_display_0(void) {
  // 显示之前清屏
  display.clearDisplay();

  display.drawBitmap(14, 12 * (-4 -currentLine), bmp_custom, 100, 12, 1);

  // 不成立
  // display.drawBitmap(16 * 1, 12 * (-3 - currentLine), hans_title, 16 * 5, 16, 1);

  display.drawBitmap(16 * 1, 12 * (-3 - currentLine), hans_title_kh_start, 16, 16, 1);
  display.drawBitmap(16 * 2, 12 * (-3 - currentLine), hans_title_lin, 16, 16, 1);
  display.drawBitmap(16 * 3, 12 * (-3 - currentLine), hans_title_jiang, 16, 16, 1);
  display.drawBitmap(16 * 4, 12 * (-3 - currentLine), hans_title_xian, 16, 16, 1);
  display.drawBitmap(16 * 5, 12 * (-3 - currentLine), hans_title_kh_end, 16, 16, 1);

  // 英文字符宽度为高度的一半
  display.drawBitmap(14 * 5, 12 * (-1.6 - currentLine), hans_author_tips, 7, 14, 1);
  display.drawBitmap(14 * 5.5, 12 * (-1.6 - currentLine), hans_author_tips, 7, 14, 1);
  display.drawBitmap(14 * 6, 12 * (-1.6 - currentLine), hans_author_kongge, 7, 14, 1);
  display.drawBitmap(14 * 6.5, 12 * (-1.6 - currentLine), hans_author_yang, 14, 14, 1);
  display.drawBitmap(14 * 7.5, 12 * (-1.6 - currentLine), hans_author_shen, 14, 14, 1);

  // 显示文字 (左上角x坐标,左上角y坐标, 图形数组, 图形宽度像素点, 图形高度像素点, 设置颜色)
  display.drawBitmap(14 * 1, 12 * (0 - currentLine), hans_gun, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (0 - currentLine), hans_gun, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (0 - currentLine), hans_chang, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (0 - currentLine), hans_jiang, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (0 - currentLine), hans_dong, 12, 12, 1);
  display.drawBitmap(14 * 6, 12 * (0 - currentLine), hans_shi, 12, 12, 1);
  display.drawBitmap(14 * 7, 12 * (0 - currentLine), hans_shui, 12, 12, 1);


  display.drawBitmap(14 * 1, 12 * (1 - currentLine), hans_lang, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (1 - currentLine), hans_hua, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (1 - currentLine), hans_tao, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (1 - currentLine), hans_jin, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (1 - currentLine), hans_ying, 12, 12, 1);
  display.drawBitmap(14 * 6, 12 * (1 - currentLine), hans_xiong, 12, 12, 1);


  display.drawBitmap(14 * 1, 12 * (2 - currentLine), hans_shi1, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (2 - currentLine), hans_fei, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (2 - currentLine), hans_cheng, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (2 - currentLine), hans_bai, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (2 - currentLine), hans_zhuan, 12, 12, 1);
  display.drawBitmap(14 * 6, 12 * (2 - currentLine), hans_tou, 12, 12, 1);
  display.drawBitmap(14 * 7, 12 * (2 - currentLine), hans_kong, 12, 12, 1);


  display.drawBitmap(14 * 1, 12 * (3 - currentLine), hans_qing, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (3 - currentLine), hans_shan, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (3 - currentLine), hans_yi, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (3 - currentLine), hans_jiu, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (3 - currentLine), hans_zai, 12, 12, 1);


  display.drawBitmap(14 * 1, 12 * (4 - currentLine), hans_ji2, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (4 - currentLine), hans_du, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (4 - currentLine), hans_xi, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (4 - currentLine), hans_yang, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (4 - currentLine), hans_hong, 12, 12, 1);

  display.drawBitmap(14 * 1, 12 * (6 - currentLine), hans_bai1, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (6 - currentLine), hans_fa, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (6 - currentLine), hans_yu, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (6 - currentLine), hans_qiao, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (6 - currentLine), hans_jiang, 12, 12, 1);
  display.drawBitmap(14 * 6, 12 * (6 - currentLine), hans_zhu, 12, 12, 1);
  display.drawBitmap(14 * 7, 12 * (6 - currentLine), hans_shang, 12, 12, 1);


  display.drawBitmap(14 * 1, 12 * (7 - currentLine), hans_guan, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (7 - currentLine), hans_kan, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (7 - currentLine), hans_qiu, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (7 - currentLine), hans_yue, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (7 - currentLine), hans_chun, 12, 12, 1);
  display.drawBitmap(14 * 6, 12 * (7 - currentLine), hans_feng, 12, 12, 1);


  display.drawBitmap(14 * 1, 12 * (8 - currentLine), hans_yi1, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (8 - currentLine), hans_hu, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (8 - currentLine), hans_zhuo, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (8 - currentLine), hans_jiu1, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (8 - currentLine), hans_xi1, 12, 12, 1);
  display.drawBitmap(14 * 6, 12 * (8 - currentLine), hans_xiang, 12, 12, 1);
  display.drawBitmap(14 * 7, 12 * (8 - currentLine), hans_feng1, 12, 12, 1);


  display.drawBitmap(14 * 1, 12 * (9 - currentLine), hans_gu, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (9 - currentLine), hans_jin1, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (9 - currentLine), hans_duo, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (9 - currentLine), hans_shao, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (9 - currentLine), hans_shi2, 12, 12, 1);


  display.drawBitmap(14 * 1, 12 * (10 - currentLine), hans_dou, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (10 - currentLine), hans_fu, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (10 - currentLine), hans_xiao, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (10 - currentLine), hans_tan, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (10 - currentLine), hans_zhong, 12, 12, 1);




  // display.drawBitmap(14 * 1, 12, hans_, 12, 12, 1);
  // display.drawBitmap(14 * 2, 12, hans_, 12, 12, 1);
  // display.drawBitmap(14 * 3, 12, hans_, 12, 12, 1);
  // display.drawBitmap(14 * 4, 12, hans_, 12, 12, 1);
  // display.drawBitmap(14 * 5, 12, hans_, 12, 12, 1);
  // display.drawBitmap(14 * 6, 12, hans_, 12, 12, 1);
  // display.drawBitmap(14 * 7, 12, hans_, 12, 12, 1);


  currentLine += 0.1;

  //显示图形
  display.display();
  delay(1);

  if (currentLine > 13) {
    currentLine = -9;
  }
  Serial.println(currentLine);
}

void hans_display_1(void) {
  // 显示之前清屏
  display.clearDisplay();

  display.drawBitmap(14 * 1, 12 * (0 - currentLine), hans_bai1, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (0 - currentLine), hans_fa, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (0 - currentLine), hans_yu, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (0 - currentLine), hans_qiao, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (0 - currentLine), hans_jiang, 12, 12, 1);
  display.drawBitmap(14 * 6, 12 * (0 - currentLine), hans_zhu, 12, 12, 1);
  display.drawBitmap(14 * 7, 12 * (0 - currentLine), hans_shang, 12, 12, 1);


  display.drawBitmap(14 * 1, 12 * (1 - currentLine), hans_guan, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (1 - currentLine), hans_kan, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (1 - currentLine), hans_qiu, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (1 - currentLine), hans_yue, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (1 - currentLine), hans_chun, 12, 12, 1);
  display.drawBitmap(14 * 6, 12 * (1 - currentLine), hans_feng, 12, 12, 1);


  display.drawBitmap(14 * 1, 12 * (2 - currentLine), hans_yi1, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (2 - currentLine), hans_hu, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (2 - currentLine), hans_zhuo, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (2 - currentLine), hans_jiu1, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (2 - currentLine), hans_xi1, 12, 12, 1);
  display.drawBitmap(14 * 6, 12 * (2 - currentLine), hans_xiang, 12, 12, 1);
  display.drawBitmap(14 * 7, 12 * (2 - currentLine), hans_feng1, 12, 12, 1);


  display.drawBitmap(14 * 1, 12 * (3 - currentLine), hans_gu, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (3 - currentLine), hans_jin1, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (3 - currentLine), hans_duo, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (3 - currentLine), hans_shao, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (3 - currentLine), hans_shi2, 12, 12, 1);


  display.drawBitmap(14 * 1, 12 * (4 - currentLine), hans_dou, 12, 12, 1);
  display.drawBitmap(14 * 2, 12 * (4 - currentLine), hans_fu, 12, 12, 1);
  display.drawBitmap(14 * 3, 12 * (4 - currentLine), hans_xiao, 12, 12, 1);
  display.drawBitmap(14 * 4, 12 * (4 - currentLine), hans_tan, 12, 12, 1);
  display.drawBitmap(14 * 5, 12 * (4 - currentLine), hans_zhong, 12, 12, 1);

  // display.drawBitmap(20 * 1, 16 * 3, hans_tai, 16, 16, 1);
  // display.drawBitmap(20 * 2, 16 * 3, hans_ji, 16, 16, 1);
  // display.drawBitmap(20 * 3, 16 * 3, hans_chuang, 16, 16, 1);
  // display.drawBitmap(20 * 4, 16 * 3, hans_ke, 16, 16, 1);

  // // 显示文字 (左上角x坐标,右上角y坐标, 图形数组, 图形宽度像素点, 图形高度像素点, 设置颜色)
  // display.drawBitmap(20 * 1, 16, hans_tai1, 32, 32, 1);
  // display.drawBitmap(20 * 2, 16, hans_ji1, 32, 32, 1);
  // display.drawBitmap(20 * 3, 16, hans_chuang1, 32, 32, 1);
  // display.drawBitmap(20 * 4, 16, hans_ke1, 32, 32, 1);

  //显示图形
  display.display();
  delay(4000);
}