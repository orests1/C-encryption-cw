#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
	XOR algorithm using key
	By Alex Allain
	http://www.cprogramming.com/tutorial/xor.html
*/
int xor(char* InFile,char* OutFile,int key)
{   key=atoi(key);
	printf("XOR Mode...\n");
	char *in[2];
	in[0]='d';
	char f[1];
	f[0]=InFile;
	char *buf[2];
	char n[1];
	char *buf2[2];
	n[0]=OutFile;	
	strcpy(buf,f);
	strcpy(buf2,n);
	// the above is for getting the correct InFile and OutFile for the strncmp to work
	int retIn;
	int retOut;		
	retIn = strncmp(buf,in,1);  // compares InFile with default ( 1 if I have input , 0 if I don't)
	retOut= (strncmp(buf2,in,1));  // compares OutFile with default (1 if I have output and 0 if I don't)	
	if (retIn==0)
	{ // No input 
		int c;	
		int next;
		char* buffer[2048]; 
		printf("Enter any string: ");
		char* message = fgets(buffer,2048,stdin);	//gets message from user	
		FILE *temp = fopen("temp.txt", "w"); // creating temporary file to make encryption possible
		fprintf(temp,"%s",message);
		fclose(temp);
		FILE *temp2 = fopen("temp.txt","rb"); 
		if (retOut==0)  
		{ // No input , no output

			if(message==NULL)
			{
				printf("Error: No input!\n");		
			}
			else 
			{
				printf("Processing.\n");				
				while((c = fgetc(temp2)) != EOF)
				{
					next=((int)c^key);	
					printf("%c",next); 				
				}
				printf("\nCompleted!\n");
				fclose(temp2);
			}
		}
		else if (retOut!=0)
		{//No input , yes output

			char *outFile;	
			int next;
			int c;			
			outFile = fopen(OutFile, "w");
			if(message==NULL)
			{
				printf("Error: No input!\n");		
			}
			else 
			{

				printf("Processing.\n");
				while((c = fgetc(temp2)) != EOF)
				{					
					
					next=((int)c^key);
					fprintf(outFile,"%c",next);					 				
				}
				printf("Completed!\n");
				fclose(temp2);
				fclose(outFile);
			}			
		}
		int status=remove("temp.txt"); // deletes unnecessary temp file
	}	
	else if (retIn!=0)
	{// Yes input
	
		if (retOut==0)
		{// Yes input , No output

			FILE *inFile;
			int next;
			int c;
			inFile = fopen(InFile,"rb");

			printf("Processing.\n");
			while((c = fgetc(inFile)) != EOF)	
			{				
				
				next=((int)c^key);
				printf("%c",next); 				
			}
			printf("\nCompleted!\n");
			fclose(inFile);
		}
		else if (retOut!=0)
		{ // Yes input , yes output
			FILE *inFile;
			FILE *outFile;	
			int next;
			int c;
			inFile = fopen(InFile,"rb");
			outFile = fopen(OutFile, "w");
			if(inFile==NULL)
			{
				printf("Error: Can't Open file!\n");		
			}
			else 
			{
				printf("Processing.\n");
				while((c = fgetc(inFile)) != EOF)	
				{			
					
					next=((int)c^key);
					fprintf(outFile,"%c",next);
				}
				printf("Completed!\n");
				fclose(inFile);
				fclose(outFile);				
			}
		}
	}
	
	return 0;
	
}

//******************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^********************//
//*******************************XOR ALGORITHM********************************//
//******************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^********************//
//******************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^********************//
//*******************************ENCRYPTION********************************//
//******************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^********************//

int Encrypt(char* InFile,char* OutFile,int key)
{   key=atoi(key);

	char *in[2];
	in[0]='d';
	char f[1];
	f[0]=InFile;
	char *buf[2];
	char n[1];
	char *buf2[2];
	n[0]=OutFile;	
	strcpy(buf,f);
	strcpy(buf2,n);
	// the above is for getting the correct InFile and OutFile for the strncmp to work
	int retIn;
	int retOut;		
	retIn = strncmp(buf,in,1);  // compares InFile with default ( 1 if I have input , 0 if I don't)
	retOut= (strncmp(buf2,in,1));  // compares OutFile with default (1 if I have output and 0 if I don't)	
	if (retIn==0)
	{ // No input 
		printf("No input\n");
		int c;	
		int next;
		char* buffer[2048];
		printf("Enter any string: ");
		char* message = fgets(buffer,2048,stdin);	//gets message from user	
		FILE *temp = fopen("temp.txt", "w");	//temp file to enable encryption
		fprintf(temp,"%s",message);
		fclose(temp);
		FILE *temp2 = fopen("temp.txt","rb");
		if (retOut==0)
		{ // No input , no output

			if(message==NULL)
			{
				printf("Error: No input!\n");		
			}
			else 
			{

				printf("Encryption in process.\n");				
				while((c = fgetc(temp2)) != EOF)
				{
					
					next=((int)c+key)<<2;					
					printf("%04x ",next); 				
				}
				printf("\nCompleted!\n");
				fclose(temp2);
			}
		}
		else if (retOut!=0)
		{//No input , yes output

			char *outFile;	
			int next;
			int c;			
			outFile = fopen(OutFile, "w");
			if(message==NULL)
			{
				printf("Error: No input!\n");		
			}
			else 
			{

				printf("Encryption in process.\n");
				while((c = fgetc(temp2)) != EOF)
				{					
					
					next=((int)c+key)<<2;
					fprintf(outFile,"%04x ",next);					 				
				}
				printf("Completed!\n");
				fclose(temp2);
				fclose(outFile);
			}			
		}
		int status=remove("temp.txt"); 
	}	
	else if (retIn!=0)
	{// Yes input
	
		if (retOut==0)
		{// Yes input , No output

			FILE *inFile;
			int next;
			int c;
			inFile = fopen(InFile,"rb");

			printf("Encryption in process.\n");
			while((c = fgetc(inFile)) != EOF)	
			{				
				
				next=((int)c+key)<<2;				
				printf("%04x ",next); 				
			}
			printf("\nCompleted!\n");
			fclose(inFile);
		}
		else if (retOut!=0)
		{ // Yes input , yes output

			FILE *inFile;
			FILE *outFile;	
			int next;
			int c;
			inFile = fopen(InFile,"rb");
			outFile = fopen(OutFile, "w");
			if(inFile==NULL)
			{
				printf("Error: Can't Open file!\n");		
			}
			else 
			{

				printf("Encryption in process.\n");
				while((c = fgetc(inFile)) != EOF)	
				{			
					
					next=((int)c+key)<<2;
					fprintf(outFile,"%04x ",next);
				}
				printf("Completed!\n");
				fclose(inFile);
				fclose(outFile);				
			}
		}
	}
	
	return 0;
	
}

//******************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^********************//
//*******************************ENCRYPTION********************************//
//******************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^********************//
//******************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^********************//
//*******************************DECRYPTION********************************//
//******************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^********************//

int Decrypt(char *InFile,char *OutFile,int key)
{   key=atoi(key);	
	char *in[2];
	in[0]='d';
	char f[1];
	f[0]=InFile;
	char *buf[2];
	char n[1];
	char *buf2[2];
	n[0]=OutFile;	
	strcpy(buf,f);
	strcpy(buf2,n);
	// the above is for getting the correct InFile and OutFile for the strncmp to work
	int retIn;
	int retOut;	
	retIn = strncmp(buf,in,1);  // compares InFile with default ( 1 if I have input , 0 if I don't)
	retOut= strncmp(buf2,in,1);  // compares OutFile with default (1 if I have output and 0 if I don't)		
	FILE *inFile;
	FILE *outFile;
	char next;
	char c;	
	if (retIn==0)
	{ // No input 	
		char* buffer[2048];
		printf("Enter any string to Decrypt: ");
		char* message = fgets(buffer,2048,stdin);		//gets message from user
		FILE *temp = fopen("temp.txt", "w");	// creates temp file to enable decryption
		fprintf(temp,"%s",message);
		fclose(temp);
		FILE *temp2 = fopen("temp.txt","rb");			
		fseek(temp2,0,SEEK_END);
		int size=ftell(temp2);
		fseek(temp2,0,SEEK_SET);
		if (retOut==0)
		{ // No input , no output
			if(message==NULL)
			{
				printf("Error: No input!\n");		
			}
			else 
			{
				size_t space = 1;
				char* buffer = malloc(space);
				for (int i=0;i<size;i++)
				{
					c = fgetc(temp2);			
					buffer[i]=c;
					space++;
					buffer=realloc(buffer,space);
				}		
				char* end;
				long int l; long int l2;  
				end=buffer;        	
				printf("Decryption in process.\n");			
				for (int i=0 ; i<size/5;i++){		    
					l=strtol (buffer,&end,16);	
					buffer = end;
					l=(l>>2)-key;
					printf("%c",l);
				}		
				printf("\nCompleted!\n");
				
				fclose(temp2);
			}
		}
		else if (retOut!=0)
		{//No input , yes output
			outFile = fopen(OutFile, "w");
			if(message==NULL)
			{
				printf("Error: No input!\n");		
			}
			else 
			{
				size_t space = 1;
				char* buffer = malloc(space);
				for (int i=0;i<size;i++)
				{
					c = fgetc(temp2);			
					buffer[i]=c;
					space++;
					buffer=realloc(buffer,space);
				}		
				char* end;
				long int l; long int l2;  
				end=buffer;        	
				printf("Decryption in process.\n");			
				for (int i=0 ; i<size/5;i++){		    
					l=strtol (buffer,&end,16);	
					buffer = end;
					l=(l>>2)-key;
					fprintf(outFile,"%c",l);
				}		
				printf("Completed!\n");
				
				fclose(temp2);
				fclose(outFile);
			}
		}
		int status=remove("temp.txt");
	}	
	else if (retIn!=0)
	{// Yes input
		
		inFile = fopen(InFile,"rb");
		fseek(inFile,0,SEEK_END);
		int size=ftell(inFile);
		fseek(inFile,0,SEEK_SET);
		if (retOut==0)
		{// Yes input , No output
			size_t space = 1;
			char* buffer = malloc(space);
			for (int i=0;i<size;i++)
			{
				c = fgetc(inFile);			
				buffer[i]=c;
				space++;
				buffer=realloc(buffer,space);
			}		
			char* end;
			long int l; long int l2;  
			end=buffer;        	
			printf("Decryption in process.\n");			
			for (int i=0 ; i<size/5;i++){		    
				l=strtol (buffer,&end,16);	
				buffer = end;
				l=(l>>2)-key;
				printf("%c",l);
			}		
			printf("\nCompleted!\n");
			fclose(inFile);
		}
		else if (retOut!=0)
		{ // Yes input , yes output

			FILE *inFile;
			FILE *outFile;	
			int next;
			int c;
			inFile = fopen(InFile,"rb");
			outFile = fopen(OutFile, "w");
			
			if(inFile==NULL)
			{
				printf("Error: Can't Open file!\n");		
			}
			else 
			{
				size_t space = 1;
				char* buffer = malloc(space);
				for (int i=0;i<size;i++)
				{
					c = fgetc(inFile);			
					buffer[i]=c;
					space++;
					buffer=realloc(buffer,space);
				}		
				char* end;
				long int l; long int l2;  
				end=buffer;        	
				printf("Decryption in process.\n");			
				for (int i=0 ; i<size/5;i++){		    
					l=strtol (buffer,&end,16);	
					buffer = end;
					l=(l>>2)-key;					
					fprintf(outFile,"%c",l);
				}		
				printf("Completed!\n");
				fclose(inFile);
				fclose(outFile);	
			}
			
		}
	}
	
	return 0;
}
//******************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^********************//
//*******************************DECRYPTION********************************//
//******************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^********************//
//******************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^********************//
//*******************************MAIN APPLICATION********************************//
//******************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^********************//
int main(int argc, char **argv[])
{ 
	char* arg[10];	
	char* key="200";
	for (int i=0;i<10;i++)
	{
		arg[i]="z";	
	}	
	for (int i=0;i<argc;i++)
	{			
		arg[i]=argv[i];
		
	}		
	
	char *output='d';
	char *input='d';	
	int flag=0;
	int inflag=0;
	////------------------- ENCRYPT----------------------------------------
	for (int i=0;i<10;i++){	
	
		if ((strcmp(arg[i],"-e")==0) && (flag==0))
		{ //encryption
			flag=1;
			for (int i=0;i<10;i++)
			{	 		
				if (strcmp(arg[i],"-i")==0)
				{ //Input is provided
			        inflag=1;
					input=arg[i+1];	
					for (int i=0;i<10;i++)
					{	
						if (strcmp(arg[i],"-o")==0)
						{ // Output is provided
							output=arg[i+1];
							
							for (int i=0;i<10;i++){	
								if (strcmp(arg[i],"-a")==0)
								{ // Algorithm is provided
									
									for (int i=0;i<10;i++){	
										if (strcmp(arg[i],"basic")==0)
										{// Basic algorith is selected
											
											for (int i=0;i<10;i++)
											{												    
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													
													key=arg[i+1];
													Encrypt(input,output,key);													
													goto end;
												}
												else if (i==9)
												{ // default Key 200
													Encrypt(input,output,key); 													
													goto end;
												}
												
												
											}
										}
										
										else if(strcmp(arg[i],"xor")==0)
										{ 
											for (int i=0;i<10;i++)
											{												    
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													
													key=arg[i+1];
													xor(input,output,key);													
													goto end;
												}
												else if (i==9)
												{ // default Key 200
													xor(input,output,key); 													
													goto end;
												}
											}
										} 
										
									}
								}
				                else if (i==9)
				                { //no -a. Default algorithm is basic
									for (int i=0;i<10;i++){
				                   	    if (strcmp(arg[i],"-k")==0)
					                    { // Key is provided
											key=arg[i+1];
					                     	Encrypt(input,output,key); 
											goto end;
										}
										else if (i==9)
				                     	{ // default Key 200
					                     	Encrypt(input,output,key); 
											goto end;
										}
									}  
								}
							}
						}
			            else if ((i==9))
			            { // Default output is STDOUT
							//output = d  flag for STDOUT
							output='d';
							for (int i=0;i<10;i++)
							{  
								if (strcmp(arg[i],"-a")==0)
								{ // Algorithm is provided
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"basic")==0)
										{// Basic algorithm is selected
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													key=arg[i+1];
													Encrypt(input,output,key);
													goto end;
												}
												else if (i==9)
												{ // default Key 200
													Encrypt(input,output,key);  
													goto end;
												}
											}
										}
										
										if (strcmp(arg[i],"xor")==0)
										{// xor algorithm is selected
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													key=arg[i+1];
													xor(input,output,key); 
													goto end;
												}
												else if (i==9)
												{ // default Key 200
													xor(input,output,key);
													goto end;
												}
											}
										}
										else if (i==9)
										{ // Default algorithm is basic
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													Encrypt(input,output,key);  
													goto end;
												}
												else if (i==9)
												{ // default Key 200
													Encrypt(input,output,key);
													goto end;
												}
											}
										}
									}
								}								
								else if (i==9)
								{ // Default algorithm is basic
									
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"-k")==0)
										{ // Key is provided
											key=arg[i+1];
											Encrypt(input,output,key);
											goto end;
										}
										else if (i==9)
										{ // Keys is not provided.
											Encrypt(input,output,key); 
											goto end;
										}				
									}			
								}
								
							}				
						}
					}
				}
				
				else if ((i==9))
				{
					//Default read from STDIN					
					input='d';					
					for (int i=0;i<10;i++)
					{
						if (strcmp(arg[i],"-o")==0)
						{ //Output is provided
							output=arg[i+1];
							for (int i=0;i<10;i++)
							{
								if (strcmp(arg[i],"-a")==0)
								{// Algorithm is provided.
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"basic")==0)
										{// Basic algorithm is selected
											for (int i=0;i<10;i++)
											{
												if(strcmp(arg[i],"-k")==0)
												{// Key is provided
													key=arg[i+1];	
													Encrypt(input,output,key); 
													goto end;
												}
												else 
												{// No key is provided
													Encrypt(input,output,key);  
													goto end;
												}
											}
										}
										
										else if (strcmp(arg[i],"xor")==0)
										{// xor algorithm is selected
											
											for (int i=0;i<10;i++)
											{
												if(strcmp(arg[i],"-k")==0)
												{// Key is provided
													key=arg[i+1];	
													xor(input,output,key); 
													goto end;
												}
												else 
												{// No key is provided
													xor(input,output,key); 
													goto end;
												}
											}
										}
										
										else if(i==9)
										{//Wrong name of algorithm
											for (int i=0;i<10;i++)
											{
												if(strcmp(arg[i],"-k")==0)
												{// Key is provided
													key=arg[i+1];
													Encrypt(input,output,key);  
													goto end;
												}
												else if (i==9)
												{// No key is provided
													Encrypt(input,output,key);  
													goto end;
												}
											}
										}										
									}
								}
								else if (i==9)
								{// no algorithm is provided
									for (int i=0;i<10;i++)
									{
										if(strcmp(arg[i],"-k")==0)
										{// Key is provided
											key=arg[i+1];
											Encrypt(input,output,key); 
											goto end;
										}
										else if (i==9)
										{// No key is provided
											Encrypt(input,output,key); 
											goto end;
										}
									}	
								}								
							}
						}
						else if (i==9)
						{ // Default output to STDOUT
							output='d';
							for (int i=0;i<10;i++)
							{
								if (strcmp(arg[i],"-a")==0)
								{// algorithm was provided
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"basic")==0)
										{// basic algorithm was selected
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{// key is provided
													key=arg[i+1];
													Encrypt(input,output,key); 
													goto end;
												}
												else if (i==9)
												{// key is default 200
													Encrypt(input,output,key); 
													goto end;
												}
											}
										}
										
										else if (strcmp(arg[i],"xor")==0)
										{// xor algorithm was selected
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{// key is provided
													key=arg[i+1];
													xor(input,output,key); 
													goto end;
												}
												else if (i==9)
												{// key is default 200	
													xor(input,output,key); 
													goto end;
												}
											}
										}
										
										else if (i==9)
										{// wrong name algorithm
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{// key is provided
													key=arg[i+1];
													Encrypt(input,output,key); 
													goto end;
												}
												else if (i==9)
												{// key is default 200
													Encrypt(input,output,key); 
													goto end;
												}
											}
										}										
									}
								}
								else if (i==9)
								{// no algorithm
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"-k")==0)
										{// key is provided
											key=arg[i+1];
											Encrypt(input,output,key); 
											goto end;
										}
										else 
										{// key is default 200
											Encrypt(input,output,key);  
											goto end;
										}
									}
								}
								
							}			
						}
						
					}
				}
				
			}
		}
		
	}
	//-------------DECRYPT-----------------------------------------------------------------------------------------------------------------------------------------------
	for (int i=0;i<10;i++)
	{			
		if ((strcmp(arg[i],"-d")==0) && (flag==0))
		{ //Decryption
			flag=1;
			for (int i=0;i<10;i++)
			{	 
				if (strcmp(arg[i],"-i")==0)
				{ //Input is provided
			        inflag=1;
					input=arg[i+1];					
					
					for (int i=0;i<10;i++)
					{	
						if (strcmp(arg[i],"-o")==0)
						{ // Output is provided
							output=arg[i+1];
							
							for (int i=0;i<10;i++){	
								if (strcmp(arg[i],"-a")==0)
								{ // Algorithm is provided
									
									for (int i=0;i<10;i++){	
										if (strcmp(arg[i],"basic")==0)
										{// Basic algorithm is selected
											
											for (int i=0;i<10;i++)
											{												    
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													key=arg[i+1];
													Decrypt(input,output,key);													
													goto end;
												}
												else if (i==9)
												{ // default Key 200
													Decrypt(input,output,key); 													
													goto end;
												}
												
												
											}
										}	
										if (strcmp(arg[i],"xor")==0)
										{// Basic algorithm is selected
											
											for (int i=0;i<10;i++)
											{												    
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													
													key=arg[i+1];
													xor(input,output,key);													
													goto end;
												}
												else if (i==9)
												{ // default Key 200
													xor(input,output,key); 													
													goto end;
												}
											}
										}
										
									}
								}
				                else if (i==9)
				                { //no -a. Default algorithm is basic		
									for (int i=0;i<10;i++){
				                   	    if (strcmp(arg[i],"-k")==0)
					                    { // Key is provided
											key=arg[i+1];
					                     	Decrypt(input,output,key); 
											goto end;
										}
										else if (i==9)
				                     	{ // default Key 200
					                     	Decrypt(input,output,key); 
											goto end;
										}
									}  
								}
							}
						}
			            else if ((i==9))
			            { // Default output is STDOUT
							output='d';
							for (int i=0;i<10;i++)
							{  
								if (strcmp(arg[i],"-a")==0)
								{ // Algorithm is provided
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"basic")==0)
										{// Basic algorithm is selected
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													key=arg[i+1];
													Decrypt(input,output,key);
													goto end;
												}
												else if (i==9)
												{ // default Key 200
													Decrypt(input,output,key);  
													goto end;
												}
											}
										}
										
										else if (strcmp(arg[i],"xor")==0)
										{// xor algorithM is selected
											
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													key=arg[i+1];
													xor(input,output,key); 
													goto end;
												}
												else if (i==9)
												{ // default Key 200
													Decrypt(input,output,key);  
													goto end;
												}
											}
										}
										
										else
										{ // Default algorithm is basic
											
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													key= arg[i+1];
													Decrypt(input,output,key);  
													goto end;
												}
												else if (i==9)
												{ // default Key 200
													Decrypt(input,output,key);   
													goto end;
												}
											}
										}
									}
								}								
								else if (i==9)
								{ // Default algorithm is basic
									
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"-k")==0)
										{ // Key is provided
											key=arg[i+1];
											Decrypt(input,output,key);
											goto end;
										}
										else if (i==9)
										{ // Keys is not provided.
											Decrypt(input,output,key);  
											goto end;
										}				
									}			
								}
								
							}				
						}
					}
				}
				
				else if ((i==9))
				{
					//Default read from STDIN					
					input='d';					
					for (int i=0;i<10;i++)
					{
						if (strcmp(arg[i],"-o")==0)
						{ //Output is provided
							output=arg[i+1];
							for (int i=0;i<10;i++)
							{
								if (strcmp(arg[i],"-a")==0)
								{// Algorithm is provided.
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"basic")==0)
										{// Basic algorithm is selected
											for (int i=0;i<10;i++)
											{
												if(strcmp(arg[i],"-k")==0)
												{// Key is provided
													key=arg[i+1];	
													Decrypt(input,output,key); 
													goto end;
												}
												else 
												{// No key is provided
													Decrypt(input,output,key); 
													goto end;
												}
											}
										}
										
										if (strcmp(arg[i],"xor")==0)
										{// Basic algorithm is selected
											for (int i=0;i<10;i++)
											{
												if(strcmp(arg[i],"-k")==0)
												{// Key is provided
													key=arg[i+1];	
													xor(input,output,key);
													goto end;
												}
												else 
												{// No key is provided
													xor(input,output,key); 
													goto end;
												}
											}
										}
										
										else if(i==9)
										{//Wrong name of algorithm
											for (int i=0;i<10;i++)
											{
												if(strcmp(arg[i],"-k")==0)
												{// Key is provided
													key=arg[i+1];
													Decrypt(input,output,key); 
													goto end;
												}
												else if (i==9)
												{// No key is provided
													Decrypt(input,output,key); 
													goto end;
												}
											}
										}										
									}
								}
								else if (i==9)
								{// no algorithm is provided
									for (int i=0;i<10;i++)
									{
										if(strcmp(arg[i],"-k")==0)
										{// Key is provided
											key=arg[i+1];
											Decrypt(input,output,key); 
											goto end;
										}
										else if (i==9)
										{// No key is provided
											Decrypt(input,output,key); 
											goto end;
										}
									}	
								}								
							}
						}
						else if (i==9)
						{ // Default output to STDOUT
							output='d';
							for (int i=0;i<10;i++)
							{
								if (strcmp(arg[i],"-a")==0)
								{// algorithm was provided
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"basic")==0)
										{// basic algorithm was selected
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{// key is provided
													key=arg[i+1];
													Decrypt(input,output,key);  
													goto end;
												}
												else if (i==9)
												{// key is default 200
													Decrypt(input,output,key); 
													goto end;
												}
											}
										}
										
										if (strcmp(arg[i],"xor")==0)
										{// xor algorithm was selected
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{// key is provided
													key=arg[i+1];
													xor(input,output,key); 
													goto end;
												}
												else if (i==9)
												{// key is default 200
													xor(input,output,key); 
													goto end;
												}
											}
										}
										
										else if (i==9)
										{// wrong name algorithm
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{// key is provided
													key=arg[i+1];
													Decrypt(input,output,key); 
													goto end;
												}
												else if (i==9)
												{// key is default 200
													Decrypt(input,output,key); 
													goto end;
												}
											}
										}										
									}
								}
								else if (i==9)
								{// no algorithm
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"-k")==0)
										{// key is provided
											key=arg[i+1];
											Decrypt(input,output,key); 
											goto end;
										}
										else 
										{// key is default 200
											Decrypt(input,output,key); 
											goto end;
										}
									}
								}
								
							}			
						}
						
					}
				}
				
			}
		}
		
	}
	//------------DEFAULT ENCRYPT -----------------------------------------------------------------------------------------------------
	for (int i=0;i<10;i++)
	{			
		if (flag==0)
		{ //encryption
			flag=1;	
			for (int i=0;i<10;i++)
			{	 		
				if (strcmp(arg[i],"-i")==0)
				{ //Input is provided
			        inflag=1;
					input=arg[i+1];					
					
					for (int i=0;i<10;i++)
					{	
						if (strcmp(arg[i],"-o")==0)
						{ // Output is provided
							output=arg[i+1];
							
							for (int i=0;i<10;i++){	
								if (strcmp(arg[i],"-a")==0)
								{ // Algorithm is provided
									
									for (int i=0;i<10;i++){	
										if (strcmp(arg[i],"basic")==0)
										{// Basic algorithm is selected
											
											for (int i=0;i<10;i++)
											{												    
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													
													key=arg[i+1];
													Encrypt(input,output,key);													
													goto end;
												}
												else if (i==9)
												{ // default Key 200
													Encrypt(input,output,key); 													
													goto end;
												}
												
												
											}
										}	
										if (strcmp(arg[i],"xor")==0)
										{// xor algorithm is selected
											for (int i=0;i<10;i++)
											{												    
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													key=arg[i+1];
													xor(input,output,key);													
													goto end;
												}
												else if (i==9)
												{ // default Key 200	
													xor(input,output,key); 													
													goto end;
												}
												
												
											}
										} 
										
									}
								}
				                else if (i==9)
				                { //no -a. Default algorithm is basic			
									for (int i=0;i<10;i++){
				                   	    if (strcmp(arg[i],"-k")==0)
					                    { // Key is provided
											key=arg[i+1];
					                     	Encrypt(input,output,key); 
											goto end;
										}
										else if (i==9)
				                     	{ // default Key 200
					                     	Encrypt(input,output,key); 
											goto end;
										}
									}  
								}
							}
						}
			            else if ((i==9))
			            { // Default output is STDOUT
							output='d';
							for (int i=0;i<10;i++)
							{  
								if (strcmp(arg[i],"-a")==0)
								{ // Algorithm is provided
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"basic")==0)
										{// Basic algorithm is selected
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													key=arg[i+1];
													Encrypt(input,output,key); 
													goto end;
												}
												else if (i==9)
												{ // default Key 200
													Encrypt(input,output,key);   
													goto end;
												}
											}
										}
										
										if (strcmp(arg[i],"xor")==0)
										{// Basic algorithm is selected
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													key=arg[i+1];
													xor(input,output,key); 
													goto end;
												}
												else if (i==9)
												{ // default Key 200
													xor(input,output,key);  
													goto end;
												}
											}
										}
										
										else 
										{ // Default algorithm is basic
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{ // Key is provided
													key= arg[i+1];
													Encrypt(input,output,key);  
													goto end;
												}
												else if (i==9)
												{ // default Key 200
													Encrypt(input,output,key);   
													goto end;
												}
											}
										}
									}
								}								
								else if (i==9)
								{ // Default algorithm is basic
									
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"-k")==0)
										{ // Key is provided
											key=arg[i+1];
											Encrypt(input,output,key);  
											goto end;
										}
										else if (i==9)
										{ // Keys is not provided.
											Encrypt(input,output,key);  
											goto end;
										}				
									}			
								}
								
							}				
						}
					}
				}
				
				else if ((i==9))
				{
					//Default read from STDIN
					//input = d   flag for STDIN
					input='d';					
					for (int i=0;i<10;i++)
					{
						if (strcmp(arg[i],"-o")==0)
						{ //Output is provided
							output=arg[i+1];
							for (int i=0;i<10;i++)
							{
								if (strcmp(arg[i],"-a")==0)
								{// Algorithm is provided.
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"basic")==0)
										{// Basic algorithm is selected
											for (int i=0;i<10;i++)
											{
												if(strcmp(arg[i],"-k")==0)
												{// Key is provided
													key=arg[i+1];	
													Encrypt(input,output,key);  
													goto end;
												}
												else 
												{// No key is provided
													Encrypt(input,output,key);
													goto end;
												}
											}
										}
										
										if (strcmp(arg[i],"xor")==0)
										{// Basic algorithm is selected
											for (int i=0;i<10;i++)
											{
												if(strcmp(arg[i],"-k")==0)
												{// Key is provided
													key=arg[i+1];	
													xor(input,output,key);  
													goto end;
												}
												else 
												{// No key is provided
													xor(input,output,key); 
													goto end;
												}
											}
										}
										
										else if(i==9)
										{//Wrong name of algorithm
											for (int i=0;i<10;i++)
											{
												if(strcmp(arg[i],"-k")==0)
												{// Key is provided
													key=arg[i+1];
													Encrypt(input,output,key); 
													goto end;
												}
												else if (i==9)
												{// No key is provided
													Encrypt(input,output,key);  
													goto end;
												}
											}
										}										
									}
								}
								else if (i==9)
								{// no algorithm is provided
									for (int i=0;i<10;i++)
									{
										if(strcmp(arg[i],"-k")==0)
										{// Key is provided
											key=arg[i+1];
											Encrypt(input,output,key); 
											goto end;
										}
										else if (i==9)
										{// No key is provided
											Encrypt(input,output,key); 
											goto end;
										}
									}	
								}								
							}
						}
						else if (i==9)
						{ // Default output to STDOUT
							output='d';
							for (int i=0;i<10;i++)
							{
								if (strcmp(arg[i],"-a")==0)
								{// algorithm was provided
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"basic")==0)
										{// basic algorithm was selected
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{// key is provided
													key=arg[i+1];
													Encrypt(input,output,key);  
													goto end;
												}
												else if (i==9)
												{// key is default 200
													Encrypt(input,output,key);  
													goto end;
												}
											}
										}
										
										if (strcmp(arg[i],"xor")==0)
										{// basic algorithm was selected
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{// key is provided
													key=arg[i+1];
													xor(input,output,key);  
													goto end;
												}
												else if (i==9)
												{// key is default 200
													xor(input,output,key); 
													goto end;
												}
											}
										}
										
										else if (i==9)
										{// wrong name algorithm
											for (int i=0;i<10;i++)
											{
												if (strcmp(arg[i],"-k")==0)
												{// key is provided
													key=arg[i+1];
													Encrypt(input,output,key);  
													goto end;
												}
												else if (i==9)
												{// key is default 200
													Encrypt(input,output,key);  
													goto end;
												}
											}
										}										
									}
								}
								else if (i==9)
								{// no algorithm
									for (int i=0;i<10;i++)
									{
										if (strcmp(arg[i],"-k")==0)
										{// key is provided
											key=arg[i+1];
											Encrypt(input,output,key);  
											goto end;
										}
										else 
										{// key is default 200
											Encrypt(input,output,key);  
											goto end;
										}
									}
								}
								
							}			
						}
						
					}
				}
				
			}
		}
		
	}
	
	end:
	return 0;
}