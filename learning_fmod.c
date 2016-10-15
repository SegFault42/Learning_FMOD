#include "stdio.h"
#include "./fmod_lib/inc/fmod.h"

void	error_check(FMOD_RESULT *result)
{
	if (*result != FMOD_OK)
		printf("Error !\n");
	else
		printf("OK !\n");
}

int	main()
{
//=============================================================================
//Declaration de 2 pointeurs. "sys" pour cree l'objet fmod, "plop" pour charger le son en memoire.
	FMOD_SYSTEM *sys;
	FMOD_SOUND	*plop;
//=============================================================================

	FMOD_CHANNEL *channel = 0;
	/*FMOD_CHANNELGROUP *channelgroup;*/
	FMOD_RESULT result;
//=============================================================================
//Creation et initialisation de l'objet.
	result = FMOD_System_Create(&sys);
	error_check(&result);
	result = FMOD_System_Init(sys, 32, FMOD_INIT_NORMAL, NULL);
	error_check(&result);
//=============================================================================

	/*FMOD_System_CreateChannelGroup(sys, "chanel", &channelgroup);*/
	/*result = FMOD_System_GetChannel(sys, 9, &channel);*/
	/*result = FMOD_Channel_SetChannelGroup(channel, channelgroup);*/
//=============================================================================
//Fonction pour charger le son en memoire.
	result = FMOD_System_CreateSound(sys, "./sound/plop.mp3", FMOD_DEFAULT, 0, &plop);
	error_check(&result);
//=============================================================================

//=============================================================================
//Lecture du son.
	result = FMOD_System_PlaySound(sys, plop, 0, 0, &channel);
	error_check(&result);
//=============================================================================

//=============================================================================
//Free le son charger en memoire
	result = FMOD_Sound_Release(plop);
	error_check(&result);
//=============================================================================

//=============================================================================
//Fonction pour fermer l'objet et free la memoire
	result = FMOD_System_Close(sys);
	error_check(&result);
	result = FMOD_System_Release(sys);
	error_check(&result);
//=============================================================================
}
