#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define kMAXNUM 20
#define kNOMBRE 20
#define kvidamax 500
#define kTIPO 10
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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
void MostrarPokemon(TPokemon, int );
void MostrarNombres(TPokemon, int );
void IntroducirPokemon(TPokemon *);
void ElegirPokemon(TPokemon[], int *);
void GenerarOponente(TPokemon[], int, int, int *);
void Combate(TPokemon [],  TPokemon [], int );

int main()
{

  printf("\n");
  printf(ANSI_COLOR_RED"                                        pp                                      \n"ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED"ooooooooo.            oooo             pp                                       \n"ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED"`888   `Y88.          `888                                                      \n"ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED" 888   .d88' .ooooo.   888  oooo   .ooooo.  ooo..oo. .oo.    .ooooo.  ooo. .oo. \n"ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED" 888ooo88P' d88' `88b  888 .8P'   d88' `88b `888PY88bPY88b  d88' `88b `888P'Y88b\n"ANSI_COLOR_RESET);
  printf(" 888        888   888  888888.    888ooo888  888  888  888  888   888  888   888\n");
  printf(" 888        888   888  888 `88b.  888    .o  888  888  888  888   888  888   888\n");
  printf("o888o       `Y8bod8P' o888o o888o `Y8bod8P' o888  888o 888o `Y8bod8P' o888o o888\n");
  printf("\n");
  printf("🔴🍚                                                                        🍚🔴\n");
  printf("\n");



  printf(ANSI_COLOR_RED "            ######################            \n" ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED "         ############################         \n" ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED "      ##################################      \n" ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED "    ######################################    \n" ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED "   ########################################   \n" ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED "  ##########################################  \n" ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED "  ##########################################  \n" ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED "  ##################       #################  \n" ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED "  ################           ###############  \n" ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED "  ##############  " ANSI_COLOR_RESET   "  POKÉMON  " ANSI_COLOR_RED   "  #############  \n" ANSI_COLOR_RESET);

  printf("  ##############       C       #############  \n");
  printf("  ################           ###############  \n");
  printf("  ##################       #################  \n");
  printf("  ##########################################  \n");
  printf("  ##########################################  \n");
  printf("   ########################################   \n");
  printf("    ######################################    \n");
  printf("      ##################################      \n");
  printf("         ############################         \n");
  printf("            ######################            \n");
  printf("\n");


  srand (time (NULL)); 

  int numpokemon = 10, opcion, i;
  TPokemon pokemon[kMAXNUM];
  TPokemon oponentes[kMAXNUM];
  RellenarPokemon(pokemon);
  RellenarPokemon(oponentes);

  do
  {

    opcion = Menu();
    printf("\n");

    switch (opcion)
    {
    case 1:                                             //se muestran los pokémon disponibles con stats (si hay alguno ya introducido)
      if (numpokemon > 0)
      {
        for (i = 0; i < numpokemon; i++)
        {
          printf("----------------------\n");
          printf("%d)", i+1);
          MostrarPokemon(pokemon[i], i+1);
        }
          printf("----------------------\n");
      }
      else
      {
        printf("No hay pokémon introducidos\n");
      }
      break;

    case 2:                                             //se introduce un nuevo pokémon (si no se ha superado el máx)
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
    case 3:                                             //parte de combate
      for (i = 0; i < numpokemon; i++)
      {
        printf("----------------------\n");
        printf("%d)", i+1);
        MostrarNombres(pokemon[i], i+1); //muestra solo nombre y tipo de los pokémon
      }
        printf("----------------------\n");
      Combate(pokemon,oponentes,numpokemon);
    }

  } while (opcion != 4);

  printf("¡Hasta luego! \n");
}

int Menu()                                       //este módulo muestra las opciones del menú y gestiona que el usuario meta una opcion valida
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

void RellenarPokemon(TPokemon pokemon[])              //este módulo rellena automaticamente la lista de pokémon con los datos que se introduzcan
{
  strcpy(pokemon[0].nombre, "Charmander");
  strcpy(pokemon[0].tipo, "Fuego");
  pokemon[0].estadisticas.ataque = 100;
  pokemon[0].estadisticas.defensa = 150;
  pokemon[0].estadisticas.vida = 200;

  strcpy(pokemon[1].nombre, "Ninetales");
  strcpy(pokemon[1].tipo, "Fuego");
  pokemon[1].estadisticas.ataque = 200;
  pokemon[1].estadisticas.defensa = 200;
  pokemon[1].estadisticas.vida = 300;

  strcpy(pokemon[2].nombre, "Quilav");
  strcpy(pokemon[2].tipo, "Fuego");
  pokemon[2].estadisticas.ataque = 150;
  pokemon[2].estadisticas.defensa = 150;
  pokemon[2].estadisticas.vida = 300;

  strcpy(pokemon[3].nombre, "Dratini");
  strcpy(pokemon[3].tipo, "Dragón");
  pokemon[3].estadisticas.ataque = 150;
  pokemon[3].estadisticas.defensa = 160;
  pokemon[3].estadisticas.vida = 200;

  strcpy(pokemon[4].nombre, "Axew");
  strcpy(pokemon[4].tipo, "Dragón");
  pokemon[4].estadisticas.ataque = 150;
  pokemon[4].estadisticas.defensa = 200;
  pokemon[4].estadisticas.vida = 200;

  strcpy(pokemon[5].nombre, "Starmie");
  strcpy(pokemon[5].tipo, "Agua");
  pokemon[5].estadisticas.ataque = 200;
  pokemon[5].estadisticas.defensa = 180;
  pokemon[5].estadisticas.vida = 300;

  strcpy(pokemon[6].nombre, "Lapras");
  strcpy(pokemon[6].tipo, "Agua");
  pokemon[6].estadisticas.ataque = 200;
  pokemon[6].estadisticas.defensa = 200;
  pokemon[6].estadisticas.vida = 400;

  strcpy(pokemon[7].nombre, "Slowpoke");
  strcpy(pokemon[7].tipo, "Agua");
  pokemon[7].estadisticas.ataque = 170;
  pokemon[7].estadisticas.defensa = 170;
  pokemon[7].estadisticas.vida = 300;

  strcpy(pokemon[8].nombre, "Togetic");
  strcpy(pokemon[8].tipo, "Hada");
  pokemon[8].estadisticas.ataque = 120;
  pokemon[8].estadisticas.defensa = 200;
  pokemon[8].estadisticas.vida = 300;

  strcpy(pokemon[9].nombre, "Enamorus");
  strcpy(pokemon[9].tipo, "Hada");
  pokemon[9].estadisticas.ataque = 200;
  pokemon[9].estadisticas.defensa = 200;
  pokemon[9].estadisticas.vida = 400;
}

void MostrarPokemon(TPokemon p, int i)  //módulo que muestra los pokémon con todos sus datos (stats incluidas), se llama cuando en el menú principal se elige la opción de mostrar
{
  if (i<10){
  printf(" Nombre: %s \n", p.nombre);
  printf("   Tipo: %s \n", p.tipo);
  printf("   Ataque: %d \n", p.estadisticas.ataque);
  printf("   Defensa: %d \n", p.estadisticas.defensa);
  printf("   Vida: %d \n", p.estadisticas.vida);
  }

  else{                                //este else es solo para arreglar y que quede bonito porque si el número era 10 o más no quedaba alineado al hacer printf
  printf(" Nombre: %s \n", p.nombre);
  printf("    Tipo: %s \n", p.tipo);
  printf("    Ataque: %d \n", p.estadisticas.ataque);
  printf("    Defensa: %d \n", p.estadisticas.defensa);
  printf("    Vida: %d \n", p.estadisticas.vida);
  }

}

void MostrarNombres(TPokemon p, int i) //módulo que muestra solo el nombre y tipo de los pokémon disponibles, se llama cuando se elige la opción de combatir
{
  if (i<10){
  printf(" Nombre: %s \n", p.nombre);
  printf("   Tipo: %s \n", p.tipo);
  }

  else{                                //este else es solo para arreglar y que quede bonito porque si el número era 10 o más no quedaba alineado al hacer printf
  printf(" Nombre: %s \n", p.nombre);
  printf("    Tipo: %s \n", p.tipo);
  }

}

void IntroducirPokemon(TPokemon *p) //módulo que permite introducir un nuevo pokémon siempre que no se haya superado el número máximo (fijado por la constante kMAXNUM)
{
  printf("Introduce su nombre: ");
  scanf("%s", p->nombre);
  printf("Introduce su tipo: ");
  scanf("%s", p->tipo);
  printf("Introduce su ataque: ");
  scanf("%d", &(*p).estadisticas.ataque);
  printf("Introduce su defensa: ");
  scanf("%d", &(*p).estadisticas.defensa);
  printf("Introduce su vida: ");
  scanf("%d", &(*p).estadisticas.vida);
}

void ElegirPokemon(TPokemon pokemon[], int *elegido)
{
  int eleg, cambiar;

  do{                                                              //parte para elegir un pokémon, te enseña sus estadísticas y te deja cambiar
    printf("¡Elige tu Pokemon!\n");
    scanf("%d", &eleg);
    printf("----------------------\n");
    printf("Has elegido a %s \n",pokemon[eleg-1].nombre);
    printf("----------------------\n");
    printf("%s tiene las siguientes estadísticas: \n", pokemon[eleg-1].nombre);
    printf("Ataque: %d \n", pokemon[eleg-1].estadisticas.ataque);
    printf("Defensa: %d \n", pokemon[eleg-1].estadisticas.defensa);
    printf("Vida: %d \n", pokemon[eleg-1].estadisticas.vida);

    do{
      printf("----------------------\n");
      printf("Quieres cambiar de Pokémon?\nSí|1|  No|0|\n");
      scanf("%d", &cambiar);
      if (cambiar!=1 && cambiar!=0)
        printf("No es un número válido\n");
    }while(cambiar!=1 && cambiar!=0);
    
  }while(cambiar==1);
    

  *elegido = eleg;

}

void GenerarOponente(TPokemon oponentes[], int numpokemon, int elegido, int *oponente)
{
  int opo, cambiar;

  do{                                                              //parte para generar un oponente aleatorio, te deja generar otro
  do{
  opo = rand() % (numpokemon-1);
  }while(opo == elegido-1);
  printf("Tu oponente es %s \n",oponentes[opo].nombre);
  do{
    printf("Quieres cambiar de Pokemon?\nSí|1|  No|0|\n");
    scanf("%d", &cambiar);
    if (cambiar!=1 && cambiar!=0)
        printf("No es un número válido\n");
  }while(cambiar!=1 && cambiar!=0);
  }while(cambiar==1);


  *oponente = opo;

}


void Combate(TPokemon pokemon[], TPokemon oponentes[], int numpokemon) //módulo de combate (hay que dividirlo para que no sea tan largo)
{
  
  int i;
  int elegido, oponente, vida_elegido, vida_oponente;
  int accion, reaccion;
  int danyo_oponente = 0, danyo_elegido = 0;
  int vida_perdida_elegido, vida_perdida_oponente;

  ElegirPokemon(pokemon, &elegido);
  GenerarOponente(oponentes, numpokemon, elegido, &oponente);

  printf("\t¡¡¡Adelante %s!!!\n", pokemon[elegido-1].nombre);      //parte donde comienza el combate

  vida_oponente=(oponentes[oponente].estadisticas.vida*5)/100;    //se calcula el numero de asteriscos que tendrá cada pokémon en su barra de vida
  vida_elegido=(pokemon[elegido-1].estadisticas.vida*5)/100;

  do
  {
    printf("--------------------------------------\n");
    printf("%s ", oponentes[oponente].nombre);
    printf("\n");
    for(i=0;i<vida_oponente;i++)                                    //se imprimen las barras de vida
    {
      printf("*");
    }
    printf("\n\tVS\n");

    for(i=0;i<vida_elegido;i++)
    {
      printf("*");
    }

    printf("\n");
    printf("%s ",pokemon[elegido-1].nombre );
    printf("\n");
    do{
    printf("Atacar|1|  Defender|0|\n");
    scanf("%i", &accion);
    if (accion!=0 && accion!=1)
      printf("XX Tu número no es válido XX \n");
    }while (accion!=0 && accion!=1);

 
    reaccion = rand() % 2;                       //el oponente ataca o se defiende aleatoriamente
    printf("\n");


    if (reaccion == 0 && accion == 1)
    {
      printf("\t%s)<<%s\n ",oponentes[oponente].nombre,pokemon[elegido-1].nombre);
      printf("%s se ha defendido\n ",oponentes[oponente].nombre );
      if (pokemon[elegido-1].estadisticas.ataque > oponentes[oponente].estadisticas.defensa)
      {
        danyo_oponente = pokemon[elegido-1].estadisticas.ataque - oponentes[oponente].estadisticas.defensa;
      }
      else
      {
        printf("La defensa del oponente es mayor o igual que tu ataque, así que no ha recibido daño \n");
      }
    }

    else if (reaccion == 1 && accion == 0)
    {
      printf("\t%s>>(%s\n ",oponentes[oponente].nombre,pokemon[elegido-1].nombre);
      printf("\t%s ataca nuestra defensa\n ",oponentes[oponente].nombre);
      if (oponentes[oponente].estadisticas.ataque > pokemon[elegido-1].estadisticas.defensa)
      {
        danyo_elegido = oponentes[oponente].estadisticas.ataque - pokemon[elegido-1].estadisticas.defensa;
      }
      else
      {
        printf("Tu defensa es mayor o igual que el ataque del enemigo, así que no recibes daño \n");
      }
    }

    else if (reaccion == 1 && accion == 1)
    {
      printf("\t%s>>X<<%s\n ",oponentes[oponente].nombre,pokemon[elegido-1].nombre);
      printf("\t%s y %s han recibido daño mutuamente\n ",oponentes[oponente].nombre,pokemon[elegido-1].nombre);
      danyo_elegido = oponentes[oponente].estadisticas.ataque; 
      danyo_oponente = pokemon[elegido-1].estadisticas.ataque;
    }

    else if (reaccion == 0 && accion == 0)
    {
      printf("\t%s)  (%s\n ",oponentes[oponente].nombre,pokemon[elegido-1].nombre);
      printf("\t%s también se ha defendido\n ",oponentes[oponente].nombre);
      printf("Nadie recibe daño \n");
    }

    //ahora se resta el daño de la vida

    printf("%s -%d\n ", pokemon[elegido-1].nombre, danyo_elegido);
    printf("%s -%d\n", oponentes[oponente].nombre, danyo_oponente);

    vida_perdida_elegido = (danyo_elegido*5)/100;
    vida_perdida_oponente = (danyo_oponente*5)/100;

    vida_elegido = vida_elegido - vida_perdida_elegido;
    vida_oponente = vida_oponente - vida_perdida_oponente;

    danyo_elegido = 0;
    danyo_oponente = 0;


  } while(vida_elegido > 0 && vida_oponente > 0);

  printf("¡¡¡FIN DEL COMBATE!!! \n");
  printf("\n");

  if (vida_elegido < vida_oponente)
  {
    printf("OHH... HAS PERDIDO, EL GANADOR ES: %s \n", oponentes[oponente].nombre);
    printf("\n");
  }

  else if (vida_oponente < vida_elegido)
  {
      printf("HAS GANADO %s !!\n", pokemon[elegido-1].nombre);
      printf("\n");
  }
  else
  {
    printf(" HAN QUEDADO EMPATE \n");
    printf("\n"); 
  }
  
}