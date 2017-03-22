// pro_test.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "sgfplib.h"
HSGFPM  fplib;
#define X_SIZE 248
#define Y_SIZE 292

void matchfiles(char* file1, char* file2)
{
	struct stat statbuffer;
	int status;
        BYTE *minutiaeBuffer1; 
        BYTE *minutiaeBuffer2; 
        DWORD score;
        FILE *fp = NULL;
        long err;
	BOOL matched;

	status = stat(file1,&statbuffer);
	minutiaeBuffer1 = (BYTE*) malloc(statbuffer.st_size);
        fp=fopen(file1,"rb");   // read fingerprint image
        fread(minutiaeBuffer1,statbuffer.st_size,1,fp);
        fclose(fp);

	status = stat(file2,&statbuffer);
	minutiaeBuffer2 = (BYTE*) malloc(statbuffer.st_size);
        fp=fopen(file2,"rb");   // read fingerprint image
        fread(minutiaeBuffer2,statbuffer.st_size,1,fp);
        fclose(fp);

        err = SGFPM_GetMatchingScore(fplib,minutiaeBuffer1, minutiaeBuffer2, &score);
        printf("RET:[%ld] %s <> %s SCORE:\t%ld\n",err,file1,file2,score);
}

void match_file_and_extracted(char* file1, BYTE* minutiaeBuffer2)
{
	struct stat statbuffer;
	int status;
        BYTE *minutiaeBuffer1; 
        DWORD score;
        FILE *fp = NULL;
        long err;
	BOOL matched;

	status = stat(file1,&statbuffer);
	minutiaeBuffer1 = (BYTE*) malloc(statbuffer.st_size);
        fp=fopen(file1,"rb");   // read fingerprint image
        fread(minutiaeBuffer1,400,1,fp);
        fclose(fp);

        err = SGFPM_GetMatchingScore(fplib, minutiaeBuffer1, minutiaeBuffer2, &score);
        printf("RET:[%ld] %s <> extracted SCORE:\t%ld\n",err,file1,score);
}


int main(int argc, char* argv[])
{
   long err;
   DWORD quality;
   char kbBuffer[100];
   char kbWhichFinger[100];
   int fingerLength = 0;
   char *finger;
   BYTE imageBuffer1[X_SIZE*Y_SIZE];
   BYTE imageBuffer2[X_SIZE*Y_SIZE];
   BYTE imageBuffer3[X_SIZE*Y_SIZE];
   BYTE minutiaeBuffer1[800]; 
   BYTE minutiaeBuffer2[800]; 
   BYTE minutiaeBuffer3[800]; 
   FILE *fp = NULL;
   FILE *fpout = NULL;
   DWORD score;
   DWORD size;
   char file1[100];
   char file2[100];

	printf("\n-------------------------------------\n");
	printf(  "SecuGen Algorithm Test\n");
	printf(  "-------------------------------------\n");

   ///////////////////////////////////////////////
   // Instantiate JFPLib object
	err = SGFPM_Create(&fplib);
	if (!fplib)
	{
		printf("ERROR - Unable to instantiate FPM object\n");
		return false;
	}
   ///////////////////////////////////////////////
   // SGFPM_InitEx()
   err = SGFPM_InitEx(fplib, X_SIZE, Y_SIZE, 500);
   printf("SGFPM_InitEx returned : [%ld]\n",err);  
	
   if (err == SGFDX_ERROR_NONE)
   {      
      err = SGFPM_SetTemplateFormat(fplib, TEMPLATE_FORMAT_ANSI378);
      printf("SGFPM_SetTemplateFormat returned : [%ld]\n",err);  

      err = SGFPM_GetMaxTemplateSize(fplib, &size);
      printf("SGFPM_GetMaxTemplateSize returned : [%ld] max size is: [%ld]\n",err, size);  

      /////////////////////////////////////////////////////////////////////////////////////////
      //EXTRACT TEMPLATES
      fp=fopen("0_10_3.raw","rb");   // read fingerprint image
      fread(imageBuffer1,X_SIZE*Y_SIZE,1,fp);
      fclose(fp);

      SGFingerInfo finger;
      finger.FingerNumber= 1;			// FingerNumber. 
      finger.ViewNumber = 1;           // Sample number
      finger.ImpressionType= 0;       // impression type. Should be 0
      finger.ImageQuality = 0;         // Image quality
      err = SGFPM_CreateTemplate(fplib, &finger, imageBuffer1, minutiaeBuffer1);
      printf("SGFPM_CreateTemplate returned : [%ld]\n",err);
      if (err == SGFDX_ERROR_NONE)
      {
	      fpout=fopen("0_10_3_extract.ansi378","wb");	// write ansi template
         err = SGFPM_GetTemplateSize(fplib, minutiaeBuffer1, &size);
         printf("SGFPM_GetTemplateSize returned : [%ld] size is: [%ld]\n",err, size);  
	      fwrite(minutiaeBuffer1,size,1,fpout);
	      fclose(fpout);
      }

      fp=fopen("1_10_3.raw","rb");   // read fingerprint image
      fread(imageBuffer2,X_SIZE*Y_SIZE,1,fp);
      fclose(fp);
      finger.FingerNumber= 1;			// FingerNumber. 
      finger.ViewNumber = 1;           // Sample number
      finger.ImpressionType= 0;       // impression type. Should be 0
      finger.ImageQuality = 0;         // Image quality
      err = SGFPM_CreateTemplate(fplib, &finger, imageBuffer2, minutiaeBuffer2);
      printf("SGFPM_CreateTemplate returned : [%ld]\n",err);
      if (err == SGFDX_ERROR_NONE)
      {
	      fpout=fopen("1_10_3_extract.ansi378","wb");	// write ansi template
         err = SGFPM_GetTemplateSize(fplib, minutiaeBuffer2, &size);
         printf("SGFPM_GetTemplateSize returned : [%ld] size is: [%ld]\n",err, size);  
	      fwrite(minutiaeBuffer2,size,1,fpout);
	      fclose(fpout);
      }


      fp=fopen("2_10_3.raw","rb");   // read fingerprint image
      fread(imageBuffer3,X_SIZE*Y_SIZE,1,fp);
      fclose(fp);
      finger.FingerNumber= 1;			// FingerNumber. 
      finger.ViewNumber = 1;           // Sample number
      finger.ImpressionType= 0;       // impression type. Should be 0
      finger.ImageQuality = 0;         // Image quality
      err = SGFPM_CreateTemplate(fplib, &finger, imageBuffer3, minutiaeBuffer3);
      printf("SGFPM_CreateTemplate returned : [%ld]\n",err);
      if (err == SGFDX_ERROR_NONE)
      {
	      fpout=fopen("2_10_3_extract.ansi378","wb");	// write ansi template
         err = SGFPM_GetTemplateSize(fplib, minutiaeBuffer3, &size);
         printf("SGFPM_GetTemplateSize returned : [%ld] size is: [%ld]\n",err, size);  
	      fwrite(minutiaeBuffer3,size,1,fpout);
	      fclose(fpout);
      }

        printf("\nTest Cross-Platform Minutiae Files\n");
        printf("__________________________________\n");
        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"0_10_3_windows.ansi378");
        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"0_10_3_sparc_solaris10.ansi378");
        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"0_10_3_x86_solaris10.ansi378");
        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"0_10_3_ibm.ansi378");
        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"0_10_3_extract.ansi378");
        matchfiles((char*)"0_10_3_sparc_solaris10.ansi378",(char*)"0_10_3_windows.ansi378");
        matchfiles((char*)"0_10_3_sparc_solaris10.ansi378",(char*)"0_10_3_x86_solaris10.ansi378");
        matchfiles((char*)"0_10_3_sparc_solaris10.ansi378",(char*)"0_10_3_ibm.ansi378");
        matchfiles((char*)"0_10_3_sparc_solaris10.ansi378",(char*)"0_10_3_extract.ansi378");
        matchfiles((char*)"0_10_3_x86_solaris10.ansi378",(char*)"0_10_3_windows.ansi378");
        matchfiles((char*)"0_10_3_x86_solaris10.ansi378",(char*)"0_10_3_ibm.ansi378");
        matchfiles((char*)"0_10_3_x86_solaris10.ansi378",(char*)"0_10_3_extract.ansi378");
        matchfiles((char*)"0_10_3_windows.ansi378",(char*)"0_10_3_ibm.ansi378");
	matchfiles((char*)"0_10_3_windows.ansi378",(char*)"0_10_3_extract.ansi378");

        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"1_10_3_windows.ansi378");
        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"1_10_3_sparc_solaris10.ansi378");
        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"1_10_3_x86_solaris10.ansi378");
        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"1_10_3_ibm.ansi378");
        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"1_10_3_extract.ansi378");
        matchfiles((char*)"0_10_3_sparc_solaris10.ansi378",(char*)"1_10_3_windows.ansi378");
        matchfiles((char*)"0_10_3_sparc_solaris10.ansi378",(char*)"1_10_3_linux.ansi378");
        matchfiles((char*)"0_10_3_sparc_solaris10.ansi378",(char*)"1_10_3_x86_solaris10.ansi378");
        matchfiles((char*)"0_10_3_sparc_solaris10.ansi378",(char*)"1_10_3_ibm.ansi378");
        matchfiles((char*)"0_10_3_sparc_solaris10.ansi378",(char*)"1_10_3_extract.ansi378");
        matchfiles((char*)"0_10_3_x86_solaris10.ansi378",(char*)"1_10_3_windows.ansi378");
        matchfiles((char*)"0_10_3_x86_solaris10.ansi378",(char*)"1_10_3_linux.ansi378");
        matchfiles((char*)"0_10_3_x86_solaris10.ansi378",(char*)"1_10_3_sparc_solaris10.ansi378");
        matchfiles((char*)"0_10_3_x86_solaris10.ansi378",(char*)"1_10_3_ibm.ansi378");
        matchfiles((char*)"0_10_3_x86_solaris10.ansi378",(char*)"1_10_3_extract.ansi378");
        matchfiles((char*)"0_10_3_windows.ansi378",(char*)"1_10_3_x86_solaris10.ansi378");
        matchfiles((char*)"0_10_3_windows.ansi378",(char*)"1_10_3_linux.ansi378");
        matchfiles((char*)"0_10_3_windows.ansi378",(char*)"1_10_3_sparc_solaris10.ansi378");
        matchfiles((char*)"0_10_3_windows.ansi378",(char*)"1_10_3_ibm.ansi378");
        matchfiles((char*)"0_10_3_windows.ansi378",(char*)"1_10_3_extract.ansi378");
        matchfiles((char*)"0_10_3_ibm.ansi378",(char*)"1_10_3_x86_solaris10.ansi378");
        matchfiles((char*)"0_10_3_ibm.ansi378",(char*)"1_10_3_linux.ansi378");
        matchfiles((char*)"0_10_3_ibm.ansi378",(char*)"1_10_3_sparc_solaris10.ansi378");
        matchfiles((char*)"0_10_3_ibm.ansi378",(char*)"1_10_3_windows.ansi378");
        matchfiles((char*)"0_10_3_ibm.ansi378",(char*)"1_10_3_extract.ansi378");

        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"2_10_3_windows.ansi378");
        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"2_10_3_sparc_solaris10.ansi378");
        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"2_10_3_x86_solaris10.ansi378");
        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"2_10_3_ibm.ansi378");
        matchfiles((char*)"0_10_3_linux.ansi378",(char*)"2_10_3_extract.ansi378");
        matchfiles((char*)"0_10_3_sparc_solaris10.ansi378",(char*)"2_10_3_windows.ansi378");
        matchfiles((char*)"0_10_3_sparc_solaris10.ansi378",(char*)"2_10_3_linux.ansi378");
        matchfiles((char*)"0_10_3_sparc_solaris10.ansi378",(char*)"2_10_3_x86_solaris10.ansi378");
        matchfiles((char*)"0_10_3_sparc_solaris10.ansi378",(char*)"2_10_3_ibm.ansi378");
        matchfiles((char*)"0_10_3_sparc_solaris10.ansi378",(char*)"2_10_3_extract.ansi378");
        matchfiles((char*)"0_10_3_x86_solaris10.ansi378",(char*)"2_10_3_windows.ansi378");
        matchfiles((char*)"0_10_3_x86_solaris10.ansi378",(char*)"2_10_3_linux.ansi378");
        matchfiles((char*)"0_10_3_x86_solaris10.ansi378",(char*)"2_10_3_sparc_solaris10.ansi378");
        matchfiles((char*)"0_10_3_x86_solaris10.ansi378",(char*)"2_10_3_ibm.ansi378");
        matchfiles((char*)"0_10_3_x86_solaris10.ansi378",(char*)"2_10_3_extract.ansi378");
        matchfiles((char*)"0_10_3_windows.ansi378",(char*)"2_10_3_x86_solaris10.ansi378");
        matchfiles((char*)"0_10_3_windows.ansi378",(char*)"2_10_3_linux.ansi378");
        matchfiles((char*)"0_10_3_windows.ansi378",(char*)"2_10_3_sparc_solaris10.ansi378");
        matchfiles((char*)"0_10_3_windows.ansi378",(char*)"2_10_3_ibm.ansi378");
        matchfiles((char*)"0_10_3_windows.ansi378",(char*)"2_10_3_extract.ansi378");
        matchfiles((char*)"0_10_3_ibm.ansi378",(char*)"2_10_3_windows.ansi378");
        matchfiles((char*)"0_10_3_ibm.ansi378",(char*)"2_10_3_sparc_solaris10.ansi378");
        matchfiles((char*)"0_10_3_ibm.ansi378",(char*)"2_10_3_x86_solaris10.ansi378");
        matchfiles((char*)"0_10_3_ibm.ansi378",(char*)"2_10_3_linux.ansi378");
        matchfiles((char*)"0_10_3_ibm.ansi378",(char*)"2_10_3_extract.ansi378");

        matchfiles((char*)"1_10_3_linux.ansi378",(char*)"2_10_3_windows.ansi378");
        matchfiles((char*)"1_10_3_linux.ansi378",(char*)"2_10_3_sparc_solaris10.ansi378");
        matchfiles((char*)"1_10_3_linux.ansi378",(char*)"2_10_3_x86_solaris10.ansi378");
        matchfiles((char*)"1_10_3_linux.ansi378",(char*)"2_10_3_ibm.ansi378");
        matchfiles((char*)"1_10_3_linux.ansi378",(char*)"2_10_3_extract.ansi378");
        matchfiles((char*)"1_10_3_sparc_solaris10.ansi378",(char*)"2_10_3_windows.ansi378");
        matchfiles((char*)"1_10_3_sparc_solaris10.ansi378",(char*)"2_10_3_linux.ansi378");
        matchfiles((char*)"1_10_3_sparc_solaris10.ansi378",(char*)"2_10_3_x86_solaris10.ansi378");
        matchfiles((char*)"1_10_3_sparc_solaris10.ansi378",(char*)"2_10_3_ibm.ansi378");
        matchfiles((char*)"1_10_3_sparc_solaris10.ansi378",(char*)"2_10_3_extract.ansi378");
        matchfiles((char*)"1_10_3_x86_solaris10.ansi378",(char*)"2_10_3_windows.ansi378");
        matchfiles((char*)"1_10_3_x86_solaris10.ansi378",(char*)"2_10_3_linux.ansi378");
        matchfiles((char*)"1_10_3_x86_solaris10.ansi378",(char*)"2_10_3_sparc_solaris10.ansi378");
        matchfiles((char*)"1_10_3_x86_solaris10.ansi378",(char*)"2_10_3_ibm.ansi378");
        matchfiles((char*)"1_10_3_x86_solaris10.ansi378",(char*)"2_10_3_extract.ansi378");
        matchfiles((char*)"1_10_3_windows.ansi378",(char*)"2_10_3_x86_solaris10.ansi378");
        matchfiles((char*)"1_10_3_windows.ansi378",(char*)"2_10_3_linux.ansi378");
        matchfiles((char*)"1_10_3_windows.ansi378",(char*)"2_10_3_sparc_solaris10.ansi378");
        matchfiles((char*)"1_10_3_windows.ansi378",(char*)"2_10_3_ibm.ansi378");
        matchfiles((char*)"1_10_3_windows.ansi378",(char*)"2_10_3_extract.ansi378");
        matchfiles((char*)"1_10_3_ibm.ansi378",(char*)"2_10_3_windows.ansi378");
        matchfiles((char*)"1_10_3_ibm.ansi378",(char*)"2_10_3_sparc_solaris10.ansi378");
        matchfiles((char*)"1_10_3_ibm.ansi378",(char*)"2_10_3_x86_solaris10.ansi378");
        matchfiles((char*)"1_10_3_ibm.ansi378",(char*)"2_10_3_linux.ansi378");
        matchfiles((char*)"1_10_3_ibm.ansi378",(char*)"2_10_3_extract.ansi378");        
        
   }

}


