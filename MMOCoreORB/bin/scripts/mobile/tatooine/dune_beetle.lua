dune_beetle = Creature:new {
	objectName = "@mob/creature_names:dune_beetle",
	socialGroup = "beetle",
	pvpFaction = "",
	faction = "",
	level = 13,
	chanceHit = 0.29,
	damageMin = 120,
	damageMax = 130,
	baseXp = 714,
	baseHAM = 1200,
	baseHAMmax = 1400,
	armor = 0,
	resists = {15,15,0,0,0,0,0,-1,-1},
	meatType = "meat_insect",
	meatAmount = 6,
	hideType = "hide_scaley",
	hideAmount = 8,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0.25,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
	creatureBitmask = PACK + KILLER,
	optionsBitmask = 128,
	diet = HERBIVORE,

	templates = {"object/mobile/giant_sand_beetle.iff"},
	lootGroups = {},
	weapons = {"creature_spit_small_yellow"},
	conversationTemplate = "",
	attacks = {
	}
}

CreatureTemplates:addCreatureTemplate(dune_beetle, "dune_beetle")