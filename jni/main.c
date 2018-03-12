
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
//#include <linux/time.h>
  void myCallback(u_char * uchar, const struct pcap_pkthdr *  packet,
			     const u_char * data)
			     {

	//  struct timeval {
	//   time_t tv_sec;
	 //  suseconds_t tv_usec;
	//  };

			bpf_u_int32 length=     packet->caplen;
			  bpf_u_int32 plen=   packet->len;
			struct    timeval time=  packet->ts;
              //  printf("*******************start************************\n");
                printf("the cap len: %d,the pcaket len:%d\n    ",length,plen);
                printf("the timeinfo:tv_sec:%ld, tv_usec:%ld\n",time.tv_sec,time.tv_usec);
                int i;
                for(i=0;i<packet->len;i++)
                printf("%02x",data[i]);
            //    printf("\n******************end*************************\n\n\n");
                printf("\n");

			     }
int main()
{


     char error_buffer[100];
	char *device;
   	device= pcap_lookupdev(error_buffer);
	if(device)
	{
		printf("pcap_lookupdev successful\n%s\n",device);
	}else
	{
		printf("fault:\n");
		printf("%s\n",error_buffer);
	}
     char error_buffer2[100];
     pcap_t* pPcap_t=    pcap_open_live("wlan0",65535,0,-1,error_buffer2);
	if(pPcap_t)
	{
		printf("open successful\n");
	}else
	{
		printf("fault:\n");
		printf("%s\n",error_buffer2);	
	}
     unsigned char error_buffer1[100];
   int n= pcap_loop(pPcap_t,5,myCallback,error_buffer1);


   printf("%d:%s",n,error_buffer1);

   scanf("%d",&n);

    return 0;
}
