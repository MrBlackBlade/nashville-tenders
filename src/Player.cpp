#include <Player.hpp>

Player::Player
(
	const std::int32_t& idle_ind_p,
	const std::int32_t& run_ind_p,
	const std::int32_t& jump_ind_p,
	const std::int32_t& player_scale_p,
	const std::int32_t& sprite_size_run_p,
	const std::int32_t& sprite_sizeH_run_p,
	const std::int32_t& sprite_size_idle_p,
	const std::int32_t& sprite_sizeH_idle_p,
	const std::int32_t& sprite_size_jump_p,
	const std::int32_t& sprite_sizeH_jump_p,
	const std::int32_t& anims_idle_p,
	const std::int32_t& anims_run_p,
	const std::int32_t& anims_jump_p,
	const std::int32_t& velocity_p,
	const std::int32_t& velocity_max_p,
	const std::int16_t& id_p,
	const bool& idle_p
)
 {
	this->idle_ind			=  idle_ind_p;
	this->run_ind			=  run_ind_p;
	this->jump_ind          = jump_ind_p;
	this->player_scale		=  player_scale_p;
	this->sprite_size_run	=  sprite_size_run_p;
	this->sprite_sizeH_run  = sprite_sizeH_run_p;
	this->sprite_size_idle	=  sprite_size_idle_p;
	this->sprite_sizeH_idle = sprite_sizeH_idle_p;
	this->sprite_size_jump  = sprite_size_jump_p;
	this->sprite_sizeH_jump = sprite_sizeH_jump_p;
	this->anims_idle		=  anims_idle_p;
	this->anims_run			=  anims_run_p;
	this-> anims_jump       = anims_jump_p;
	this->velocity			=  velocity_p;
	this->velocity_max		=  velocity_max_p;
	this->id				=  id_p;
	this->idle				=  idle_p;
};