//
// Created by lichong on 2017/7/24.
//
#include <iostream>
#include <sys/types.h>
#include <unistd.h>   //getuid()
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <jni.h>
#include <time.h>
#include "com_example_lichong_capturer_CapturePacket.h"
#define JNI_FALSE 0
#define JNI_TRUE 1
using namespace std;
void myCallback(u_char * uchar, const struct pcap_pkthdr *  packet,const u_char * data)
{
	bpf_u_int32 length=     packet->caplen;
	bpf_u_int32 plen=   packet->len;
	string filename="/sdcard/wifi/data/myFile";
	ofstream writer((filename+".tmp").c_str(),ios::app);
	writer<<"the cap len: "<<length<<"the pcaket len: "<<plen<<endl;
	writer.close();
}

JNIEXPORT jboolean JNICALL Java_com_example_lichong_capturer_CapturePacket_setMonitor
  (JNIEnv *, jobject)
  {
    return JNI_FALSE;
  }


JNIEXPORT jboolean JNICALL Java_com_example_lichong_capturer_CapturePacket_startCapture
(JNIEnv *env, jobject obj)
{
    system("su -c /system/capture/capture");
    return JNI_TRUE;
}

JNIEXPORT jboolean JNICALL Java_com_example_lichong_capturer_CapturePacket_endCapture
  (JNIEnv *, jobject)
{
	return JNI_TRUE;
}
