#include "shared.h"
#include "video_sdl.h"
#include "sound.h"
#include "file.h"
#include "input.h"

#include <SDL/SDL.h>

bool KEY_E_DOWN=false;

void input_update() {
	SDL_Event event;

	while(SDL_PollEvent(&event)) {
		if(r_menu) {
			switch(event.type) {
				case SDL_QUIT: Game::run=false; break;

				case SDL_KEYDOWN:
					switch(event.key.keysym.sym) {
						case SDLK_w:	if(menu_choice) --menu_choice; else menu_choice=6;		break;

						case SDLK_s:	if(menu_choice<6) ++menu_choice; else menu_choice=0;	break;

						case SDLK_e:
							switch(menu_choice) {
                                                                case 1:
                                                                        r_menu=false;
                                                                        r_pokemenu=true;
                                                                        menu_text = "Select a pokemon.";
                                                                        info_dialog(menu_text);
								        soundevents.push_back(new Sound(soundbuffers[0]));
							        	soundevents.back()->play();
                                                                        break;
								case 4:
									savegame();
									soundevents.push_back(new Sound(soundbuffers[0]));
									soundevents.back()->play();
									r_menu=false;
								break;
								case 6: Game::run=false; break;
							}
						break;

						case SDLK_SPACE:	r_menu=false;		break;
						default:break;
					}
			}
		}
                else if(r_pokemenu)
                {
			switch(event.type) {
				case SDL_QUIT: Game::run=false; break;

				case SDL_KEYDOWN:
					switch(event.key.keysym.sym) {
						case SDLK_w:	if(poke_choice) --poke_choice; else poke_choice=5;		break;

						case SDLK_s:	if(poke_choice<5) ++poke_choice; else poke_choice=0;	break;

						case SDLK_e:
							switch(menu_choice) {
                                                          // POKEMON NOT IMPLEMENTED YET!
                                                          default:
                                                                  break;
							}
						break;

						case SDLK_SPACE:
                                                        r_pokemenu=false;
                                                        r_menu = true;
                                                        menu_text = "";
                                                        info_dialog(menu_text);
                                                        break;
						default:break;
					}
			}
                }
		else {
			switch(event.type) {
				case SDL_QUIT: Game::run=false; break;

				case SDL_KEYDOWN:
					switch(event.key.keysym.sym) {
						case SDLK_a:		if(!player.talking) player.start(4);	break;

						case SDLK_w:		if(!player.talking) player.start(8);	break;

						case SDLK_s:		if(!player.talking) player.start(16);	break;

						case SDLK_d:		if(!player.talking) player.start(2);	break;

						case SDLK_e:		KEY_E_DOWN=true;	break;

						case SDLK_SPACE:
							if(!player.talking) {
								player.stop();
								r_menu=true;
								soundevents.push_back(new Sound(soundbuffers[0]));
								soundevents.back()->play();
							}
						break;
						default: break;
					}
				break;

				case SDL_KEYUP:
					switch(event.key.keysym.sym) {
						case SDLK_a:		if(player.direction()==4) player.stop();	break;

						case SDLK_w:		if(player.direction()==8) player.stop();	break;

						case SDLK_s:		if(player.direction()==16) player.stop();	break;

						case SDLK_d:		if(player.direction()==2) player.stop();	break;

						case SDLK_e:		KEY_E_DOWN=false;							break;
						default: break;
					}
				break;
			}
		}
	}
}

