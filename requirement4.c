#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/wait.h>

int getnumberofpassedstudents(int start,int end,int*stuents,int P)
{
    int numofpassedstudents=0;
    for(int i=start;i<end;i=i+2)
    {
        // printf("%d %d\n",stuents[i]+stuents[i+1],getpid());
        if(stuents[i]+stuents[i+1]>P)
            numofpassedstudents++;
    }
    return numofpassedstudents;
}

int main(int argc,char*args[])
{
    int parentid=getpid();
    FILE* input;
    int N=atoi(args[2]);
    int P=atoi(args[3]);
    input=fopen(args[1],"r");
    int S;
    // array of students
    int * students=malloc(2*S*sizeof(int));
    // read the students
    if (input != NULL)
    {
        fscanf(input,"%d",&S);
        for (int i = 0; i < 2*S; i++)
        {
            fscanf(input,"%d",&students[i]);
        }
        
    }
    int segment=S/N; // segment for each process
    // make the array of children and initialize with -1 
    int * children=malloc(N*sizeof(int));
    for (int i = 0; i < N; i++)
    {
        int id=fork();
        if(id==-1)
            perror("error");
        else if(id==0)
        {
            int val;
            if(i==N-1)
            {
                val=getnumberofpassedstudents(i*2*segment,2*S,students,P);
            }
            else
            {
                val=(getnumberofpassedstudents(i*2*segment,(i+1)*2*segment,students,P));
            }
            exit(val);
            break;
        }
    else{
        children[i]=id;
    }
    }
    // wait for each process to terminate 
    int * output;
    int status;
    if (getpid()==parentid)
    {
    output=malloc(N*sizeof(int));
        for (int i = 0; i < N; i++)
    {
        waitpid(children[i],&status,0);
        if(WIFEXITED(status))
            output[i]=WEXITSTATUS(status);
    }
    }
    // print the output
    if (getpid()==parentid)
    {
       printf("Expected output:\n");
        for (int i = 0; i < N; i++)
        {
            if (i==N-1)
            {
                printf("%d\n",output[i]);
            }
            else{
                printf("%d ",output[i]);
            }
            
        }
    }
    
    
}
