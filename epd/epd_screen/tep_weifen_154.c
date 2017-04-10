#include "delay.h"
#include <string.h>
#include "mini_fs.h"
#include "epd_choose.h"
#include "epd_io.h"
#include "sys_init.h"
#include "global_variable.h"
#include "sys_isr.h"


#ifdef EPD_WF_154_TEP

const unsigned char  G_Ultrachip_154[] =
{
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0x1f,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x1f,0x0f,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0x0f,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0x63,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0x79,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7c,0xf3,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7e,0x07,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,
  0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xfc,0x00,0x03,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xfc,0x00,0x03,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xf9,0xf3,0xff,0xff,0xc7,0xcf,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xf9,0xf3,0xff,0xff,0x87,0xc7,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xf9,0xf3,0xff,
  0xff,0x3f,0xf3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,
  0xf9,0xf3,0xff,0xff,0x7e,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xfc,0xf9,0xf3,0xff,0xff,0x7e,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfc,0x70,0xe3,0xff,0xff,0x3c,0x73,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x00,0x07,0xff,0xff,0x81,0x07,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x06,0x0f,0xff,0xff,
  0xc3,0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xf8,0x03,0xfe,0x3d,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x1c,0xff,0xff,0xff,0xcf,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xce,0x7f,0xff,0xff,0x8e,
  0x03,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xce,0x7f,
  0xff,0xff,0x3e,0x03,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xfc,0xce,0x7f,0xff,0xff,0x7f,0x7b,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xf9,0xe7,0xfc,0xce,0x7f,0xff,0xff,0x7f,0xbb,0x80,0x00,0x00,0x00,0x01,0xff,
  0xff,0xff,0xff,0xdf,0xfa,0xfb,0xfe,0x44,0x7f,0xff,0xff,0x3f,0x3b,0x80,0x00,0x00,
  0x00,0x01,0xff,0xff,0xff,0xff,0xdf,0xfb,0x7b,0xfc,0x00,0xff,0xff,0xff,0x80,0x3b,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xcf,0xfb,0xbb,0xfc,0x01,0xff,0xff,
  0xff,0xc0,0xfb,0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xfc,0x00,0x07,0xfb,0xc7,0xfd,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x00,0x03,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x00,0x00,0x00,0x01,0xff,0xff,
  0xfc,0x00,0x03,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x00,0x00,0x00,
  0x01,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x00,0x7f,0xff,0xff,0x3f,0x8f,0x80,
  0x00,0x00,0x00,0x01,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x00,0x7f,0xff,0xff,
  0x0f,0x87,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x7f,
  0xff,0xff,0xff,0x47,0xf3,0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xfc,0xff,0xff,0xff,0xff,0x63,0xfb,0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0x79,0xfb,0x80,0x00,0x00,0x00,0x01,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x7f,0xff,0xff,0xff,0x7c,0xf3,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x3f,0xff,0xff,0xff,0x7e,
  0x07,0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xff,0xff,0xd3,0xfc,0xe7,0xfc,0x00,0x7f,
  0xff,0xff,0x7f,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc3,0xfb,0xfb,
  0xfc,0x00,0x7f,0xff,0xff,0xff,0xff,0x80,0x00,0x00,0x00,0x01,0xfc,0x07,0xff,0xff,
  0xe3,0xfb,0xbb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x00,0x00,0x00,0x01,0xf8,
  0x03,0xff,0xff,0xff,0xfb,0xbb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x00,0x00,
  0x00,0x01,0xf3,0xf9,0xff,0xff,0xff,0xfc,0x47,0xff,0xff,0xff,0xff,0xff,0xf3,0xff,
  0x80,0x00,0x00,0x00,0x01,0xf7,0xfd,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xf4,0xff,0x80,0x00,0x00,0x00,0x01,0xf7,0xfd,0xff,0xff,0xff,0xfe,0x7f,0xfc,
  0x00,0x7f,0xff,0xff,0xf6,0x7f,0xff,0xff,0xff,0xff,0xff,0xf3,0xf9,0xff,0xff,0xff,
  0xfe,0xbf,0xfc,0x00,0x7f,0xff,0xff,0xf7,0x9f,0x80,0x00,0x00,0x00,0x01,0xf8,0x03,
  0xff,0xff,0xff,0xfe,0xcf,0xff,0xf9,0xff,0xff,0xff,0xf7,0xe7,0x80,0x00,0x00,0x00,
  0x01,0xfc,0x07,0xff,0xff,0xff,0xfe,0xf7,0xff,0xfc,0xff,0xff,0xff,0x00,0x03,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x03,0xff,0xfe,0x7f,0xff,0xff,
  0x00,0x03,0xff,0xff,0xff,0xff,0xff,0xf9,0xf3,0xff,0xff,0xff,0xfe,0xff,0xff,0xfe,
  0x7f,0xff,0xff,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xf1,0xf1,0xfc,0x7f,0x1f,0xff,
  0xff,0xff,0xfe,0x7f,0xff,0xff,0xf7,0xff,0x80,0x00,0x00,0x00,0x01,0xf7,0xfd,0xfc,
  0x3f,0x07,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x00,0x00,0x00,0x01,
  0xf7,0xbd,0xfc,0x1f,0x03,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x00,
  0x00,0x00,0x01,0xf7,0xbd,0xfc,0x8f,0xe3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
  0x1f,0xff,0xff,0xff,0xff,0xff,0xf0,0x01,0xfc,0xc7,0xf3,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0x80,0x07,0xff,0xff,0xff,0xff,0xff,0xf8,0x43,0xfc,0xe3,0xf3,0xff,0xff,
  0xff,0x83,0xff,0xff,0xff,0x9f,0xe7,0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xfc,0xf1,
  0xe3,0xff,0xff,0xfe,0x00,0xff,0xff,0xff,0x7f,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xfc,0xf8,0x03,0xff,0xff,0xfe,0x64,0xff,0xff,0xff,0x7f,0xfb,0x80,0x00,0x00,
  0x00,0x01,0xf7,0xff,0xfc,0xfc,0x07,0xff,0xff,0xfc,0xe6,0x7f,0xff,0xff,0x7f,0xfb,
  0xff,0xff,0xff,0xff,0xff,0xf7,0xff,0xfc,0xfe,0x0f,0xfc,0x83,0xfc,0xe6,0x7f,0xff,
  0xff,0x9f,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xdb,0xfc,
  0xe6,0x7f,0xff,0xff,0x80,0x07,0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xff,0xff,0xff,
  0xfb,0xdb,0xfc,0xe6,0x7f,0xff,0xff,0xf0,0x1f,0x80,0x00,0x00,0x00,0x01,0xff,0xff,
  0xff,0xff,0xff,0xfb,0xdb,0xfc,0x64,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0x9f,0xff,0xfc,0x3b,0xfe,0x20,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x1c,0x3f,0xff,0xff,0xff,0x23,0xff,0xff,0xff,
  0xff,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x1c,0x03,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xfb,0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xfc,0x7c,0x03,0xfc,
  0x0f,0xff,0xff,0xff,0xff,0xff,0x3f,0xfb,0xff,0xff,0xff,0xff,0xff,0xfc,0x07,0xfc,
  0xfc,0x43,0xfb,0xd7,0xfc,0x00,0x7f,0xff,0xff,0x07,0xfb,0xff,0xff,0xff,0xff,0xff,
  0xf8,0x03,0xfc,0xfe,0x73,0xfb,0xdb,0xfc,0x00,0x7f,0xff,0xff,0xc0,0xfb,0xff,0xff,
  0xff,0xff,0xff,0xf3,0xf9,0xfc,0xfe,0x73,0xfb,0xdb,0xff,0xf8,0xff,0xff,0xff,0xf8,
  0x1b,0x80,0x00,0x00,0x00,0x01,0xf7,0xfd,0xfc,0x7c,0x73,0xfc,0x37,0xff,0xfc,0xff,
  0xff,0xff,0xff,0x03,0x80,0x00,0x00,0x00,0x01,0xf7,0xfd,0xfe,0x00,0x73,0xff,0xff,
  0xff,0xfe,0x7f,0xff,0xff,0xff,0xe3,0xff,0xff,0xff,0xff,0xff,0xf3,0xf9,0xfe,0x00,
  0xf3,0xff,0xfb,0xff,0xfe,0x7f,0xff,0xff,0xff,0xff,0x80,0x00,0x00,0x00,0x01,0xf8,
  0x03,0xff,0x81,0xf3,0xff,0xfb,0xff,0xfc,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xfc,0x07,0xff,0xff,0xff,0xff,0xfb,0xfc,0x00,0x7f,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0xfb,0xfc,0x00,0xff,0xff,
  0xff,0xcf,0xff,0x80,0x00,0x00,0x00,0x01,0xf9,0x83,0xff,0xc0,0x3f,0xfe,0x1b,0xff,
  0xff,0xff,0xff,0xff,0x8e,0x03,0x80,0x00,0x00,0x00,0x01,0xf1,0x01,0xff,0x00,0x0f,
  0xff,0xe3,0xff,0xff,0xff,0xff,0xff,0x3e,0x03,0xff,0xff,0xff,0xff,0xff,0xf7,0x7d,
  0xfe,0x00,0x07,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0x7b,0x80,0x00,0x00,0x00,
  0x01,0xf7,0x7d,0xfc,0x3f,0xc3,0xff,0xff,0xff,0xf9,0xff,0xff,0xff,0x7f,0xbb,0x80,
  0x00,0x00,0x00,0x01,0xf3,0x39,0xfc,0x7f,0xe3,0xfc,0x47,0xff,0xf9,0xff,0xff,0xff,
  0x3f,0x3b,0xff,0xff,0xff,0xff,0xff,0xf8,0x03,0xfc,0xff,0xf3,0xfb,0xbb,0xff,0xf9,
  0xff,0xff,0xff,0x80,0x3b,0x80,0x00,0x00,0x00,0x01,0xfc,0x07,0xfc,0x7f,0xf3,0xfb,
  0xbb,0xff,0xf9,0xff,0xff,0xff,0xc0,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,
  0x3f,0xc3,0xfb,0xbb,0xff,0xf9,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xfe,0x00,0x07,0xfc,0x47,0xff,0xf9,0xff,0xff,0xff,0xff,0xff,0x80,0x00,
  0x00,0x00,0x01,0xf7,0xff,0xff,0x00,0x0f,0xff,0xff,0xff,0xf9,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0xff,0xff,0xc0,0x3f,0xff,0xff,0xff,0xf9,0xff,
  0xff,0xff,0xf0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xf9,0xff,0xff,0xff,0x80,0x07,0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xf9,0xff,0xff,0xff,0x9f,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xfb,0x80,0x00,0x00,
  0x00,0x01,0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xfb,
  0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xfc,0x00,0x03,0xff,
  0xff,0x7f,0xfb,0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xfc,
  0x00,0x03,0xff,0xff,0x9f,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0x03,0xff,0xff,0x80,0x07,0x80,0x00,0x00,0x00,0x01,0xfc,0x07,
  0xff,0xff,0xff,0xfd,0x87,0xff,0xc0,0x1f,0xff,0xff,0xf0,0x1f,0x80,0x00,0x00,0x00,
  0x01,0xf8,0x03,0xff,0xff,0xff,0xfb,0x7b,0xfc,0x01,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xf3,0xf9,0xff,0xff,0xff,0xfb,0x7b,0xfc,0x01,0xff,0xff,0xff,
  0xff,0xff,0x80,0x00,0x00,0x00,0x01,0xf7,0xfd,0xff,0xff,0xff,0xfd,0x7b,0xff,0xc0,
  0x1f,0xff,0xff,0xf0,0x1f,0x80,0x00,0x00,0x00,0x01,0xf7,0xfd,0xff,0xff,0xff,0xfe,
  0x07,0xff,0xff,0x03,0xff,0xff,0x80,0x07,0xff,0xff,0xff,0xff,0xff,0xf3,0xf9,0xff,
  0xff,0xff,0xff,0xff,0xfc,0x00,0x03,0xff,0xff,0x9f,0xe7,0x80,0x00,0x00,0x00,0x01,
  0xf8,0x03,0xff,0xff,0xff,0xfe,0x0f,0xfc,0x00,0x03,0xff,0xff,0x7f,0xfb,0x80,0x00,
  0x00,0x00,0x01,0xfc,0x07,0xff,0xff,0xff,0xfd,0xf7,0xff,0xff,0xff,0xff,0xff,0x7f,
  0xfb,0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xff,0x9f,0xff,0xfb,0xfb,0xff,0xff,0xff,
  0xff,0xff,0x7f,0xfb,0xff,0xff,0xff,0xff,0xff,0xfc,0xe7,0xfe,0x1c,0x3f,0xfb,0xfb,
  0xff,0x83,0xff,0xff,0xff,0x9f,0xe7,0x80,0x00,0x00,0x00,0x01,0xf8,0x43,0xfe,0x1c,
  0x03,0xfd,0xf7,0xfe,0x00,0xff,0xff,0xff,0x80,0x07,0xff,0xff,0xff,0xff,0xff,0xf3,
  0x19,0xfc,0x7c,0x03,0xfe,0x0f,0xfe,0x64,0xff,0xff,0xff,0xf0,0x1f,0x80,0x00,0x00,
  0x00,0x01,0xf7,0xbd,0xfc,0xfc,0x43,0xff,0xff,0xfc,0xe6,0x7f,0xff,0xff,0xff,0xff,
  0x80,0x00,0x00,0x00,0x01,0xf7,0xbd,0xfc,0xfe,0x73,0xff,0xff,0xfc,0xe6,0x7f,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf3,0x19,0xfc,0xfe,0x73,0xff,0xff,0xfc,
  0xe6,0x7f,0xff,0xff,0xf0,0x1f,0x80,0x00,0x00,0x00,0x01,0xf8,0x43,0xfc,0x7c,0x73,
  0xff,0xff,0xfc,0xe6,0x7f,0xff,0xff,0x80,0x07,0xff,0xff,0xff,0xff,0xff,0xfc,0xe7,
  0xfe,0x00,0x73,0xff,0xff,0xfc,0x64,0x7f,0xff,0xff,0x9f,0xe7,0x80,0x00,0x00,0x00,
  0x01,0xff,0xff,0xfe,0x00,0xf3,0xff,0xff,0xfe,0x20,0xff,0xff,0xff,0x7f,0xfb,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x81,0xf3,0xff,0xff,0xff,0x23,0xff,0xff,0xff,
  0x7f,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0x7f,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0x9f,0xe7,0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xff,
  0xc0,0x3f,0xff,0xf7,0xfc,0x00,0x03,0xff,0xff,0x80,0x07,0x80,0x00,0x00,0x00,0x01,
  0xff,0xff,0xff,0x00,0x0f,0xff,0xf7,0xfc,0x00,0x03,0xff,0xff,0xf0,0x1f,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xfe,0x00,0x07,0xf8,0x03,0xff,0xf9,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x3f,0xc3,0xff,0xff,0xff,0xfc,0xff,
  0xff,0xff,0xff,0xff,0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xfc,0x7f,0xe3,0xff,0xff,
  0xff,0xfe,0x7f,0xff,0xff,0xf0,0x1f,0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xfc,0xff,
  0xf3,0xff,0xff,0xff,0xfe,0x7f,0xff,0xff,0x80,0x07,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xfc,0x7f,0xf3,0xff,0xff,0xff,0xfc,0x7f,0xff,0xff,0x9f,0xe7,0x80,0x00,0x00,
  0x00,0x01,0xff,0xff,0xfc,0x3f,0xc3,0xf9,0xe7,0xfc,0x00,0x7f,0xff,0xff,0x7f,0xfb,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x00,0x07,0xfa,0xfb,0xfc,0x00,0xff,0xff,
  0xff,0x7f,0xfb,0x80,0x00,0x00,0x00,0x01,0xff,0xff,0xff,0x00,0x0f,0xfb,0x7b,0xff,
  0xff,0xff,0xff,0xff,0x7f,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x3f,
  0xfb,0xbb,0xff,0xff,0xff,0xff,0xff,0x9f,0xe7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xfb,0xc7,0xff,0xff,0xff,0xff,0xff,0x80,0x07,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x1f,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0x3f,0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xfc,0x00,0x03,0xff,0xff,0x0f,0x87,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x00,0x03,0xff,0xff,0x47,0xf3,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x63,
  0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0x79,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0x7c,0xf3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7e,0x07,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0x0f,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
};
//---------------------
static void SPI_Delay(UINT8 xrate)
{
  ;
}

static void SPI_Write(UINT8 value){                                                           
  UINT8 i;
  
  
  SPI_Delay(1);
  for(i = 0; i < 8; i++)
  {
    EPD_W21_CLK_0;
    SPI_Delay(2);
    
    if(value & 0x80)
      EPD_W21_MOSI_1;
    else
      EPD_W21_MOSI_0;		
    value = (value << 1); 	
    SPI_Delay(2);
    __NOP();
    __NOP();
    EPD_W21_CLK_1; 
    SPI_Delay(2);
  }
}



static void EPD_W21_WriteCMD(UINT8 command){
  
  SPI_Delay(1);
  EPD_W21_CS_0;                   
  EPD_W21_DC_0;		// command write
  SPI_Write(command);
  EPD_W21_CS_1;
}
static void EPD_W21_WriteDATA(UINT8 command)
{
  
  SPI_Delay(1);
  EPD_W21_CS_0;                   
  EPD_W21_DC_1;		// command write
  SPI_Write(command);
  EPD_W21_CS_1;
}
/*
static UINT8 EPD_W21_ReadDATA(void)
{

UINT8 i,j; 

EPD_W21_MOSI_0;
EPD_WF_SDA_IN;
EPD_W21_CS_0; 
EPD_W21_DC_1;	 // command write 
j=0; 
SPI_Delay(2); 
for(i=0; i<8; i++) 
{ 
EPD_W21_CLK_0; 
SPI_Delay(20); 
j=(j<<1); 
if(EPD_READ_SDA) 
j|=0x01; 
    else 
j&=0xfe;	
SPI_Delay(5); 

EPD_W21_CLK_1; 
SPI_Delay(5); 
  } 
EPD_W21_CS_1; 
EPD_WF_SDA_OUT;
return(j); 
}
*/
static void lcd_chkstatus(void)
{
  
#define WAIT_COUNT	10	//10s��ʱ
  SetWathcDog();
  UINT8 i=WAIT_COUNT;
  
  smclk_timer_isr(FALSE, 0,0); 
  Delay_ms(30);
  while(!(isEPD_W21_BUSY) && (0 != i) ) //�ͱ�ʾæ
  {
    sys_wakeup_wait(200); 
    i--;
  }
 
  smclk_timer_isr(FALSE, 0,0); 
  if(i == 0)
    while(1);
  
}


static UINT8 display_data_reversal(UINT8 temp1)
{
  UINT8 retvalue =0,i=0;
  retvalue |= (temp1 &1);
  
  for(i=1;i<8;i++)
  {
    retvalue <<= 1;
    retvalue |=(((1<<i) & temp1) >>i);
  }
  
  return retvalue;
}
//---------------------
void Ultrachip(UINT8 color)
{
  UINT16 i;		     
  for(i=0;i<2888;i++)	     
  {
    EPD_W21_WriteDATA(G_Ultrachip_154[i]);  
  }                	     	     
}

void display_lcd(file_id_t fd)
{
  UINT16 pcnt;
  UINT8 i;
  UINT8  data[25] ,data_red[25];
  
  for (pcnt = 0; pcnt < 152; pcnt++) 
  {
    f_read(fd, (pcnt) * 19 ,data, 19);  	 
    f_read(F_BMP_RED,(pcnt) * 19 ,data_red, 19);  
    for (i = 0; i < 19; i++)
    {
      data[18-i] &= data_red[18-i];        
      EPD_W21_WriteDATA(display_data_reversal(data[18-i]));
    }   
  }  
}

void EPD_IC_Rst(void)
{
  EPD_W21_RST_1;
  Delay_us(300);
  EPD_W21_RST_0;		
  Delay_us(300);
  EPD_W21_RST_1;
  Delay_us(300);
}

void EPD_W21_Init(void){
  
  epd_spi_init();
  EPD_IC_Rst();
  EPD_IC_Rst();
  
  EPD_W21_WriteCMD(0x06);         //boost soft start
  EPD_W21_WriteDATA (0x17);		//A
  EPD_W21_WriteDATA (0x17);		//B
  EPD_W21_WriteDATA (0x17);		//C       
  
  EPD_W21_WriteCMD(0x04);  
  lcd_chkstatus();
  
  EPD_W21_WriteCMD(0x00);			//panel setting
  EPD_W21_WriteDATA(0x1f);		//KW-BF   KWR-AF	BWROTP 0f	BWOTP 1f
  EPD_W21_WriteDATA(0x0d);
  
  EPD_W21_WriteCMD(0x61);			//resolution setting
  EPD_W21_WriteDATA (0x98);        	 
  EPD_W21_WriteDATA (0x00);		
  EPD_W21_WriteDATA (0x98);
  
  EPD_W21_WriteCMD(0X50);			//VCOM AND DATA INTERVAL SETTING			
  EPD_W21_WriteDATA(0x97);		//VBDF 17|D7 VBDW 97 VBDB 57		VBDF F7 VBDW 77 VBDB 37  VBDR B7
  
}


void screen_close(void)
{
  EPD_W21_WriteCMD(0X50);
  EPD_W21_WriteDATA(0xf7);	
  EPD_W21_WriteCMD(0X02);  	//power off
  lcd_chkstatus();
  EPD_W21_WriteCMD(0X07);  	//deep sleep
  EPD_W21_WriteDATA(0xA5);
  close_epd();
}
BOOL screen_busy_fun(void)
{
#define TIMES_2S_BUSY 60                //2min
  if(epd_scn_tp.busy_times == TIMES_2S_BUSY)
  {
    while(1);
  }
  else if((isEPD_W21_BUSY))         //�߲�æ
  {
    epd_scn_tp.busy_times=0;
    epd_scn_tp.screen_busy_flag = FALSE;
    screen_close();
    return FALSE;
  }
  else
  {
    epd_scn_tp.screen_busy_flag = TRUE;
    return TRUE;
  }
}


void Init_EPD(void) 
{
  
  open_epd();
  EPD_W21_Init(); 
  SetWathcDog();
  EPD_W21_WriteCMD(0x13);	       //update grey image
  display_lcd(F_BMP_BW);  
  //Ultrachip(0xff);       
  EPD_W21_WriteCMD(0x12);        //display 

}

#endif

