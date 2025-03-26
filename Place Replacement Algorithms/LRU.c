#include<stdio.h>
int main(){
    int i,j,min,n,f,rs[25],m[10],count[10],flag[25],pf=0,next=1;
    printf("Enter the length of reference string: ");
    scanf("%d",&n);
    printf("Enter the reference string: ");
    for(i=0;i<n;i++){
        scanf("%d",&rs[i]);
        flag[i]=0;
    }
    printf("Enter the number of frames: ");
    scanf("%d",&f);
    for(j=0;j<f;j++){
        count[i]=0;
        m[i]=-1;
    }
    printf("\nThe page replacement process is:\n");
    for(i=0;i<n;i++){
        int found=0;
    for(j=0;j<f;j++){
        if(m[j]==rs[i]){
            flag[i]=1;
            count[j]=next;
            next++;
            found=1;
            break;
        }
    }
    if(!found){
        if(i<f){
            m[i]=rs[i];
            count[i]=next;
            next++;
        }
        else{
            min=0;
            for(j=1;j<f;j++){
                if(count[min]>count[j]){
                    min=j;
                }
            }
            m[min]=rs[i];
            count[min]=next;
            next++;
        }
        pf++;
    }
    for(j=0;j<f;j++){
        if(m[j]!=-1){
            printf("%d\t",m[j]);
        }
        else{
            printf("-\t");
        }
    }
    if(!found){
        printf("PAGE NO.--%d",pf);
    }
    printf("\n");
    }
    printf("\nTotal number of page faults using lru is: %d\n",pf);
    return 0;
}
