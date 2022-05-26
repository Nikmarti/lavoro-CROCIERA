#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PERSONE 100
#define NCABINE 40
#define TIPICABINE 4

int main()
{
	typedef char string[20];

	string nomi[PERSONE];
	string cognomi[PERSONE];
	int datanascitagiorno[PERSONE];
	int datanascitamese[PERSONE];
	int datanascitaanno[PERSONE];
	int cabinapersona[PERSONE];
	float spesa[PERSONE];

	int cabina[NCABINE];

	int cabinelibere[TIPICABINE];
	float costocabina[TIPICABINE];
	string tipocabina[TIPICABINE];
	int dimensionecabina[TIPICABINE];
	
	int personeregistrate;
	int personerimanenti;
	int codicefamiglia;
	int numerofamiliari;
	int familiaririmanenti;
	int idcabina;
	float totalespese;
	int i, j, k;
	int scelta;
	int n;
	
	strcpy(tipocabina[0], "Quadrupla");
	costocabina[0]=300;
	dimensionecabina[0]=4;
	strcpy(tipocabina[1], "Tripla");
	costocabina[1]=200;
	dimensionecabina[1]=3;
	strcpy(tipocabina[2], "Doppia");
	costocabina[2]=150;
	dimensionecabina[2]=2;
	strcpy(tipocabina[3], "Singola");
	costocabina[3]=90;
	dimensionecabina[3]=1;		
	
	for(i=0; i<TIPICABINE; i++)
	{
		cabinelibere[i]=NCABINE/TIPICABINE;
	}
	for(i=0; i<NCABINE; i++)
	{
		cabina[i]=-1;
	}
	for(i=0; i<PERSONE; i++)
	{
		cabinapersona[i]=-1;
		spesa[i]=0;
	}
	codicefamiglia=0;
	personeregistrate=0;
	personerimanenti=PERSONE;
	
	do
	{
		do
		{
			printf("Inserisci quante persone ci sono nel gruppo familiare presente, 0 per uscire: ");
			scanf("%d", &numerofamiliari);
			if(numerofamiliari>personerimanenti || numerofamiliari<0)
			{
				printf("Errore: reinserisci il numero delle persone!\n");
			}
		}while(numerofamiliari>personerimanenti || numerofamiliari<0);
		
		if(numerofamiliari>0)
		{
			for(i=0; i<numerofamiliari; i++)
			{
				printf("Inserisci cognome: ");
				scanf("%s", cognomi[i+personeregistrate]);
				printf("Inserisci nome: ");
				scanf("%s", nomi[i+personeregistrate]);
			
				do
				{
					printf("Inserisci il giorno di nascita: ");
					scanf("%d", &datanascitagiorno[i+personeregistrate]);
					if(datanascitagiorno[i+personeregistrate]>31 || datanascitagiorno[i+personeregistrate]<1)
					{
						printf("Reinserire il giorno\n");				
					}
				}while(datanascitagiorno[i+personeregistrate]>31 || datanascitagiorno[i+personeregistrate]<1);
				do
				{
				printf("Inserisci il mese di nascita: ");
				scanf("%d", &datanascitamese[i+personeregistrate]);
				if(datanascitamese[i+personeregistrate]>12 || datanascitamese[i+personeregistrate]<1)
					{
						printf("Reinserire il mese\n");				
					}
				}while(datanascitamese[i+personeregistrate]>12 || datanascitamese[i+personeregistrate]<1);
	
				do
				{
				printf("Inserisci l'anno di nascita: ");
				scanf("%d", &datanascitaanno[i+personeregistrate]);
				if(datanascitaanno[i+personeregistrate]>2022 || datanascitaanno[i+personeregistrate]<1920)
					{
						printf("Reinserire l'anno\n");				
					}
				}while(datanascitaanno[i+personeregistrate]>2022 || datanascitaanno[i+personeregistrate]<1920);
			}
			printf("\n");
			
			familiaririmanenti = numerofamiliari;
			while(familiaririmanenti>0)
			{
				printf("Il numero rimanente di familiari e' %d\n", familiaririmanenti); 
				for(i=0; i<TIPICABINE; i++)
				{
					printf("%d) %s Cabine disponibili: %d Costo %f$\n", i, tipocabina[i], cabinelibere[i], costocabina[i]);
				}
				do
				{
					printf("Inserisci il numero del tipo di cabina: ");
					scanf("%d", &scelta);
					if(scelta<0 || scelta>TIPICABINE-1)
					{
						printf("Errore: reinserisci il numero!\n");				
					}
					else if(cabinelibere[scelta]==0)
					{
						printf("Errore: le cabine di tipo %s sono esaurite\n", tipocabina[scelta]);
						scelta=-1;
					}
				}while(scelta<0 || scelta>TIPICABINE-1);
				printf("\n");
				
				idcabina=(NCABINE/TIPICABINE)-cabinelibere[scelta]+(NCABINE/TIPICABINE*scelta);
				cabina[idcabina]=codicefamiglia;
				cabinelibere[scelta]--;
				personerimanenti=personerimanenti-dimensionecabina[scelta];
				
				printf("Hai scelto la cabina N. %d\n", idcabina);
				printf("Chi ospitera' questa cabina?\n");
						
				j=0;
				n=dimensionecabina[scelta];
				while(j<n && familiaririmanenti>0)
				{
					for(i=0; i<numerofamiliari; i++)
					{
						if(cabinapersona[i+personeregistrate]==-1)
						{
							printf("%d) %s %s %d/%d/%d\n", i,  cognomi[i+personeregistrate],nomi[i+personeregistrate], datanascitagiorno[i+personeregistrate], datanascitamese[i+personeregistrate], datanascitaanno[i+personeregistrate]);
						}
					}
					do
					{
						printf("Inserisci il numero del passeggero: ");
						scanf("%d", &scelta);
						if(scelta<0 || scelta>numerofamiliari-1)
						{
							printf("Errore: reinserisci il numero!\n");				
						}
						else if(cabinapersona[scelta+personeregistrate]>=0)
						{
							printf("Errore: la persona e' gia' in una cabina!\n");
							scelta=-1;
						}
					}while(scelta<0 || scelta>numerofamiliari-1);
					printf("\n");
					
					cabinapersona[scelta+personeregistrate]=idcabina;
					familiaririmanenti--;
					j++;
		    	}
			}
			personeregistrate=personeregistrate+numerofamiliari;
			codicefamiglia++;
			if(personerimanenti==0)
			{
				printf("La crociera e' al completo\n");	
			}
		}
	}while(personerimanenti>0 && numerofamiliari!=0);
	printf("\n");
	
	for(i=0; i<personeregistrate; i++)
	{
		printf("Quanto ha speso %s %s: ",cognomi[i], nomi[i]);
		scanf("%f", &spesa[i]);
	}
	printf("\n");
	
	for(i=0; i<NCABINE; i++)
	{
		if(cabina[i]!=-1)
		{
			printf("Cabina %d - ", i);
			for(j=0; j<personeregistrate; j++)
			{
				if(cabinapersona[j]==i)
				{
					printf("%s %s, ", nomi[j], cognomi[j]);	
				}
			}
			printf("\n");
		}
	}
	printf("\n");
	
	printf("Spesa per ogni passeggero\n");
	for(i=0; i<personeregistrate; i++)
	{
		printf("Codice: %d - %s %s, Spesa: %f$\n", i,  cognomi[i],nomi[i], spesa[i]);
	}
	printf("\n");
	
	printf("Spesa per ogni gruppo\n");
	for(i=0; i<codicefamiglia; i++)
	{
		totalespese=0;
		for(j=0; j<NCABINE; j++)
		{
			if(i==cabina[j])
			{
				for(k=0; k<personeregistrate; k++)
				{
					if(j==cabinapersona[k])
					{
						totalespese=totalespese+spesa[k];
					}
				}
				totalespese=totalespese+costocabina[j/(NCABINE/TIPICABINE)];
			}

		}
		printf("Gruppo %d - Spesa %f$\n", i, totalespese);
	}
	printf("\n");
	return 0;
}
