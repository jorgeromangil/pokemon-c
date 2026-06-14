#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define kMAXNUM 20
#define kNOMBRE 20
#define kvidamax 500
#define kTIPO 10

typedef struct
{
  int ataque;
  int defensa;
  int vida;
} Tstats;

typedef struct
{
  char nombre[kNOMBRE];
  char tipo[kTIPO];
  Tstats estadisticas;
} TPokemon;

int Menu();
void RellenarPokemon(TPokemon[]);
void MostrarPokemon(TPokemon);
void IntroducirPokemon(TPokemon *);
void Eleccioncombate(TPokemon [], int npk,int *ele);
void Combate(TPokemon p[],TPokemon opo[], int npk,int *opn,int *elec);
void GenerarOponente(TPokemon[], int nup,int *op, int *el);
int main()
{
  srand (time (NULL)); 
  int e, o;
  int numpokemon = 10, opcion, i;
  TPokemon pokemon[kMAXNUM];
  TPokemon opo[kMAXNUM];
  RellenarPokemon(pokemon);
  RellenarPokemon(opo);

  do
  {

    opcion = Menu();
    printf("\n");

    switch (opcion)
    {
    case 1:
      if (numpokemon > 0)
      {
        for (i = 0; i < numpokemon; i++)
        {
          printf("(%d)\n", i);
          MostrarPokemon(pokemon[i]);
        }
      }
      else
      {
        printf("No hay pokémon introducidos\n");
      }
      break;

    case 2:
      if (numpokemon < kMAXNUM) // comprobar si ya hay suficientes pokemon
      {
        IntroducirPokemon(&pokemon[numpokemon]);
        numpokemon++; // incremento el número de pokemon
      }
      else
      {
        printf("No se pueden introducir más pokémon\n");
      }
      break;
    case 3:
      GenerarOponente(opo,numpokemon,&o,&e);
      for (i = 0; i < numpokemon; i++)
      {
        printf("(%d)\n", i);
        MostrarPokemon(pokemon[i]);
      }
      Eleccioncombate(pokemon,numpokemon,&e);
      Combate(pokemon,opo,numpokemon,&o,&e);
    }

  } while (opcion != 4);

  printf("¡Hasta luego! \n");
}

int Menu()
{
  int opcion = 0;

  printf("1. Mostrar pokémon disponibles \n");
  printf("2. Introducir nuevo pokémon \n");
  printf("3. Combatir \n");
  printf("4. Salir \n");

  do
  {
    printf("Introduce una opción: ");
    scanf("%d", &opcion);
    if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)
      printf("Esa no es una opción válida. \n");
  } while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);

  return opcion;
}

void RellenarPokemon(TPokemon pokemon[])
{
  strcpy(pokemon[0].nombre, "Charmander");
  strcpy(pokemon[0].tipo, "Fuego");
  pokemon[0].estadisticas.ataque = 60;
  pokemon[0].estadisticas.defensa = 50;
  pokemon[0].estadisticas.vida = 500;
  strcpy(pokemon[1].nombre, "Charmande");
  strcpy(pokemon[1].tipo, "Fuego");
  pokemon[1].estadisticas.ataque = 50;
  pokemon[1].estadisticas.defensa = 50;
  pokemon[1].estadisticas.vida = 500;
  strcpy(pokemon[2].nombre, "Charmand");
  strcpy(pokemon[2].tipo, "Fuego");
  pokemon[2].estadisticas.ataque = 50;
  pokemon[2].estadisticas.defensa = 50;
  pokemon[2].estadisticas.vida = 500;
  strcpy(pokemon[3].nombre, "Charman");
  strcpy(pokemon[3].tipo, "Fuego");
  pokemon[3].estadisticas.ataque = 50;
  pokemon[3].estadisticas.defensa = 50;
  pokemon[3].estadisticas.vida = 500;
  strcpy(pokemon[4].nombre, "Charma");
  strcpy(pokemon[4].tipo, "Fuego");
  pokemon[4].estadisticas.ataque = 50;
  pokemon[4].estadisticas.defensa = 50;
  pokemon[4].estadisticas.vida = 500;
  strcpy(pokemon[5].nombre, "Charm");
  strcpy(pokemon[5].tipo, "Fuego");
  pokemon[5].estadisticas.ataque = 50;
  pokemon[5].estadisticas.defensa = 50;
  pokemon[5].estadisticas.vida = 500;
  strcpy(pokemon[6].nombre, "Char");
  strcpy(pokemon[6].tipo, "Fuego");
  pokemon[6].estadisticas.ataque = 50;
  pokemon[6].estadisticas.defensa = 50;
  pokemon[6].estadisticas.vida = 500;
  strcpy(pokemon[7].nombre, "Cha");
  strcpy(pokemon[7].tipo, "Fuego");
  pokemon[7].estadisticas.ataque = 50;
  pokemon[7].estadisticas.defensa = 50;
  pokemon[7].estadisticas.vida = 500;
  strcpy(pokemon[8].nombre, "Ch");
  strcpy(pokemon[8].tipo, "Fuego");
  pokemon[8].estadisticas.ataque = 50;
  pokemon[8].estadisticas.defensa = 50;
  pokemon[8].estadisticas.vida = 500;
  strcpy(pokemon[9].nombre, "C");
  strcpy(pokemon[9].tipo, "Fuego");
  pokemon[9].estadisticas.ataque = 50;
  pokemon[9].estadisticas.defensa = 50;
  pokemon[9].estadisticas.vida = 500;
}

void MostrarPokemon(TPokemon p)
{
  printf("----------------------\n");
  printf("Nombre: %s \n", p.nombre);
  printf("Tipo: %s \n", p.tipo);
  printf("Ataque: %d \n", p.estadisticas.ataque);
  printf("Defensa: %d \n", p.estadisticas.defensa);
  printf("Vida: %d \n", p.estadisticas.vida);
  printf("----------------------\n");
}

void IntroducirPokemon(TPokemon *p)
{
  printf("Introduce su nombre: ");
  scanf("%s", p->nombre);
  printf("Introduce su tipo: ");
  scanf("%s", p->tipo);
  printf("Introduce sus puntos de ataque: ");
  scanf("%d", &(*p).estadisticas.ataque);
  printf("Introduce sus puntos de defensa: ");
  scanf("%d", &(*p).estadisticas.defensa);
  printf("Introduce su puntos de vida: ");
  scanf("%d", &(*p).estadisticas.vida);
}
void GenerarOponente(TPokemon oponentes[], int numpokemon, int *op, int *elegido)
{
  int opo, cambiar=1,ele;
  ele=*elegido;
  do{                                                              //parte para generar un oponente aleatorio, te deja generar otro
  do{
  opo = rand() % (numpokemon-1);
  }while(opo == ele-1);
  printf("Tu oponente es %s \n",oponentes[opo].nombre);
  printf("Quieres cambiar de oponente?\nSí|1|  No|0|\n");
  scanf("%d", &cambiar);
  }while(cambiar==1);

  *op = opo;

}
void Eleccioncombate(TPokemon p[], int npk, int *ele)
{ 
  int i;
  int e,o,cambiar=1;
  do{
  printf("¡Elige tu Pokemon!\n");
  scanf("%d", &e);
  printf("----------------------\n");
  printf("Has elegido a %s \n",p[e].nombre);
  printf("----------------------\n");
  printf("Quieres cambiar de Pokemon?\nSí|1|  No|0|\n");
  scanf("%d", &cambiar);
  }while(cambiar==1);
  printf("\t¡¡¡Adelante %s!!!\n", p[e].nombre);//parte donde comienza el combate
  *ele=e;
  
}
void Combate(TPokemon p[],TPokemon opo[], int npk,int *opn,int *elec)
{
  int i; 
  int o,e,cambiar,vidae,vidao;
  int accion;
  int reaccion=1, danyoe=0,danyoop=0;
  o=*opn;
  e=*elec;
  do{
  printf("--------------------------------------\n");
  printf("%s ", opo[o].nombre);
  printf("\n");
  for(i=0;i<vidao;i++) //se imprimen las barras de vida
  {
    vidao=(opo[o].estadisticas.vida*5)/100;
    printf("*");
  }
  printf("\n\tVS\n");

  for(i=0;i<vidae;i++)
  {
    vidae=(p[e].estadisticas.vida*5)/100;
    printf("*");
  }
  printf("\n");
  printf("%s ",p[e].nombre );
  printf("\n");
  printf("Atacar|1|  Defender|0|\n");
  printf("\n");
  scanf("%d", &accion);
  reaccion = rand() % 2;//oponente ataca o defiende 
  printf("\n");
  if(reaccion==0&&accion==1)
  {
    printf("\t%s)<<%s\n ",opo[o].nombre,p[e].nombre);
    printf("%s se ha defendido\n ",opo[o].nombre );  
    danyoop=(opo[o].estadisticas.defensa-p[e].estadisticas.ataque);
  }
  else if(reaccion==1&&accion==0)
  {
    printf("\t%s>>(%s\n ",opo[o].nombre,p[e].nombre);
    printf("\t%s ataca nuestra defensa\n ",opo[o].nombre);
    danyoe=(p[e].estadisticas.defensa-opo[o].estadisticas.ataque);
  } 
  else if(reaccion==1&&accion==1)
  {
    printf("\t%s>>X<<%s\n ",opo[o].nombre,p[e].nombre);
    printf("\t%s y %s han recibido daño mutuamente\n ",opo[o].nombre,p[e].nombre);
    danyoe=-opo[o].estadisticas.ataque; 
    danyoop=-p[e].estadisticas.ataque;
  }
   else if(reaccion==0&&accion==0)
  {
    printf("\t%s)  (%s\n ",opo[o].nombre,p[e].nombre);
    printf("\t%s también se ha defendido\n ",opo[o].nombre);
    danyoop=0;
    danyoe=0;
  }
  //ahora se resta el daño de la vida
  if(danyoop<0&&danyoe<0)
  {
    printf("%s %d\n ",p[e].nombre, danyoop);
    printf("%s %d\n ",opo[o].nombre, danyoe);
    vidao=vidao+danyoe;
    vidae=vidae+danyoop;
  }
  else if(danyoe<0)
  {
    printf("%s %d\n ",p[e].nombre, danyoop);
    vidae=vidae+danyoop;
  }
  else if(danyoop<0)
  {
    printf("%s %d\n ",opo[o].nombre, danyoe);
    vidao=vidae+danyoe;
  }
  else
  {
    printf("NULO\n");
  }
  }while(vidao>0&&vidae>0);

  if(danyoe<0)
  {
    printf("%s %d\n ",p[e].nombre, danyoop);
    vidae=vidae+danyoop;
  }
  else if(danyoop<0)
  {
    printf("%s %d\n ",opo[o].nombre, danyoe);
    vidao=vidae+danyoe;
  }




}