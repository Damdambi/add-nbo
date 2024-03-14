#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
int Four_BYTE(char []);

int main(int argc, char* argv[])
{
    uint32_t result = 0;
    for(int i=0; i<2; i++)
    {
        result += Four_BYTE(argv[i+1]);
    }
    printf("%x\n",result);
}

int Four_BYTE(char* filename)
{
    FILE* fp = fopen(filename, "r");
    int check = 0;
    uint32_t data = 0;

    fseek(fp, 0, SEEK_END); // Move start to end
    check = ftell(fp); // file point position
    if(check!=4) {
        perror("Not 4Byte!");
        return -1;
    }
    fseek(fp, 0, SEEK_SET); // file pointer reset
    if(fp!=NULL)
    {
        check = fread(&data, sizeof(char), 4, fp);
        if(check==4){
            fclose(fp);
            return ntohl(data);
        }
        else{
            perror("Not 4Byte!!");
            return -1;
        }
    }
    else{
        perror("File not exist");
        return -1;
    }
}
