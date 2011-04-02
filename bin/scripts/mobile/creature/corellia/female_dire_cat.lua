female_dire_cat = Creature:new {
	objectName = "@mob/creature_names:female_dire_cat",
	socialGroup = "Dire Cat",
	pvpFaction = "",
	faction = "",
	level = 10,
	chanceHit = 0.280000,
	damageMin = 120,
	damageMax = 130,
	baseXp = 430,
	baseHAM = 750,
	baseHAMmax = 750,
	armor = 0,
	resists = {0,0,15,0,0,0,0,-1,-1},
	meatType = "meat_carnivore",
	meatAmount = 65,
	hideType = "hide_bristley",
	hideAmount = 35,
	boneType = "bone_mammal",
	boneAmount = 30,
	milk = 0,
	tamingChance = 0.250000,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE,
	creatureBitmask = KILLER + PACK + HERD,
	diet = CARNIVORE,

	templates = {"object/mobile/female_dire_cat.iff"},
	lootgroups = {},
	weapons = {},
	attacks = {
		{"intimidationattack","intimidationChance=50"}
	}
}

CreatureTemplates:addCreatureTemplate(female_dire_cat, "female_dire_cat")