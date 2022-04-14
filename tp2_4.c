#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h> 

 
 struct{
        int velocidad; 
        int anio; 
        int cantidad; 
        char *tipo_cpu; 
        
}typedef compu;
 


void cargarPC(compu *EQUIPOS,char tipos[6][10]);    

void listarPC(compu *EQUIPOS);    

void listarPCVieja(compu *EQUIPOS);     

void listarPCMasRapida(compu *EQUIPOS);     
 
int main(){
             compu EQUIPOS[5]; //Arreglo de estructuras    
             
             char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"}; 
             
             cargarPC(EQUIPOS,tipos);
             listarPC(EQUIPOS);   
             listarPCVieja(EQUIPOS);   
             listarPCMasRapida(EQUIPOS);   
            
            
	printf("\n\n");
    return 0;	
}

void cargarPC(compu *EQUIPOS,char tipos[6][10]){    
  
             srand(getpid()); 

             for(int i = 0; i < 5; i++)
             {
               EQUIPOS[i].velocidad = 1 + rand()%2;
               EQUIPOS[i].anio = 2000 + rand()%17;
               EQUIPOS[i].tipo_cpu = &tipos[rand()%5][0];
               EQUIPOS[i].cantidad = 1 + rand()%3;
             }

}


void listarPC(compu *EQUIPOS){
  
            for(int i=0;i<5;i++)
           {  
              printf("PC %d\n",i+1);
              printf("----\n");
           
              printf("Velocidad: %d GHz\n",(EQUIPOS+i)->velocidad);
              printf("Anio: %d\n",(EQUIPOS+i)->anio); 
              printf("Tipo de procesador: %s\n",  (EQUIPOS+i)->tipo_cpu); 
              printf("Cantidad de nucleos: %d\n", (EQUIPOS+i)->cantidad);
               
              printf("\n\n"); 
			}
			 

}     
 
 
void listarPCVieja(compu *EQUIPOS){
  
           compu PCVIEJA[5];
           
           int pc_vieja_anio;
           int i;
           int x=1;
           int t=0;
            
           PCVIEJA[0].velocidad  = (EQUIPOS+0)->velocidad;  
           PCVIEJA[0].tipo_cpu  = (EQUIPOS+0)->tipo_cpu;  
           PCVIEJA[0].anio = pc_vieja_anio = (EQUIPOS+0)->anio;  
           PCVIEJA[0].cantidad = (EQUIPOS+0)->cantidad;  
             
           for(i=1;i<5;i++)
           {  
                 if( (EQUIPOS+i)->anio < pc_vieja_anio )
                 {
			          x=1; 
			          t=0;   
			          
			          PCVIEJA[0].velocidad  = (EQUIPOS+i)->velocidad;  
                      PCVIEJA[0].tipo_cpu  = (EQUIPOS+i)->tipo_cpu;  
                      PCVIEJA[0].anio = pc_vieja_anio = (EQUIPOS+i)->anio;  
                      PCVIEJA[0].cantidad = (EQUIPOS+i)->cantidad; 
			     }
			     else
			     { 
			           if( (EQUIPOS+i)->anio == pc_vieja_anio )
			           {
			 			    t++;
			                x++; 
					   
					        PCVIEJA[t].velocidad  = (EQUIPOS+i)->velocidad;  
                            PCVIEJA[t].tipo_cpu  = (EQUIPOS+i)->tipo_cpu;  
                            PCVIEJA[t].anio = pc_vieja_anio = (EQUIPOS+i)->anio;  
                            PCVIEJA[t].cantidad = (EQUIPOS+i)->cantidad; 
					   }
			     }
                
			}
		 	 
            if(x==1)
		    { 
		        printf("\nPC mas vieja\n");
		        printf("--------------\n"); 
		    }
		    else
		    {
		        printf("\nLas PC mas viejas\n");
		        printf("-------------------\n"); 
			}
            
            for(i=0;i<x;i++)
            { 
		       printf("Velocidad: %d GHz\n",(PCVIEJA+i)->velocidad);
               printf("Anio: %d\n",(PCVIEJA+i)->anio);
               printf("Tipo de procesador: %s\n", (PCVIEJA+i)->tipo_cpu); 
               printf("Cantidad de nucleos: %d\n", (PCVIEJA+i)->cantidad);
               
		       printf("\n"); 
		    }   
			  
}    

void listarPCMasRapida(compu *EQUIPOS){

           compu PCMASRAPIDA[5];
           
           int pc_mas_rapida;
           int i;
           int x=1;
           int t=0;
            
           PCMASRAPIDA[0].velocidad = pc_mas_rapida = (EQUIPOS+0)->velocidad;  
           PCMASRAPIDA[0].tipo_cpu  = (EQUIPOS+0)->tipo_cpu;  
           PCMASRAPIDA[0].anio = (EQUIPOS+0)->anio;  
           PCMASRAPIDA[0].cantidad = (EQUIPOS+0)->cantidad;  
             
           for(i=1;i<5;i++)
           {  
                 if( (EQUIPOS+i)->velocidad > pc_mas_rapida )
                 {
			          x=1; 
			          t=0;    
			          
			          PCMASRAPIDA[0].velocidad = pc_mas_rapida = (EQUIPOS+i)->velocidad;  
                      PCMASRAPIDA[0].tipo_cpu  = (EQUIPOS+i)->tipo_cpu;  
                      PCMASRAPIDA[0].anio = (EQUIPOS+i)->anio;  
                      PCMASRAPIDA[0].cantidad = (EQUIPOS+i)->cantidad; 
			     }
			     else
			     { 
			           if( (EQUIPOS+i)->velocidad == pc_mas_rapida )
			           {
			 			    t++;
			                x++; 
					   
					        PCMASRAPIDA[t].velocidad =  pc_mas_rapida = (EQUIPOS+i)->velocidad;  
                            PCMASRAPIDA[t].tipo_cpu  = (EQUIPOS+i)->tipo_cpu;  
                            PCMASRAPIDA[t].anio = (EQUIPOS+i)->anio;  
                            PCMASRAPIDA[t].cantidad = (EQUIPOS+i)->cantidad; 
					   }
			     }
                
			}
		 	 
            if(x==1)
		    {
		        printf("\nPC mas rapida\n");
		        printf("---------------\n");
		    }
		    else
		    {
				printf("\nLas PC mas rapidas\n");
		        printf("--------------------\n");
			}
            
            for(i=0;i<x;i++)
            { 
		       printf("Velocidad: %d GHz\n",(PCMASRAPIDA+i)->velocidad);
               printf("Anio: %d\n",(PCMASRAPIDA+i)->anio);
               printf("Tipo de procesador: %s\n", (PCMASRAPIDA+i)->tipo_cpu); 
               printf("Cantidad de nucleos: %d\n", (PCMASRAPIDA+i)->cantidad);
               
		       printf("\n"); 
		    }   


}     
