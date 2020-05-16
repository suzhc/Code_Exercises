#include<cstdio>

int main(){
    MPI_Init(NULL, NULL);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
    int X[10] = {1,2,3,4,5,6,7,8,9,10}, M[3] = {1,2,3};
    int p;
    for(int i = 0; i < 10; i++){
        if(world_rank == 0){
            MPI_Send(&i, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        }
        else{
            p = 0;
            MPI_Recv(&i, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            for(int j = 0; j < 3; j++){
                if(i-1+j<0 || i-1+j>=10) continue;
                p += X[i-1+j]*M[j];
            }
            printf("%d ", p);
        } 
    }
    printf("\n");
    return 0;
}