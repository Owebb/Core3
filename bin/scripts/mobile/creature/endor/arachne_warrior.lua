arachne_warrior = Creature:new {
	objectName = "@mob/creature_names:arachne_warrior",
	socialGroup = "Arachne",
	pvpFaction = "",
	faction = "",
	level = 42,
	chanceHit = 0.440000,
	damageMin = 355,
	damageMax = 420,
	baseXp = 4097,
	baseHAM = 10100,
	baseHAMmax = 10100,
	armor = 0,
	resists = {30,30,-1,60,60,-1,60,-1,-1},
	meatType = "meat_insect",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0.250000,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE,
	creatureBitmask = STALKER + PACK + HERD,
	diet = CARNIVORE,

	templates = {"object/mobile/angler.iff"},
	lootgroups = {},
	weapons = {"creature_spit_small_toxicgreen"},
	attacks = {
		{"blindattack","blindChance=50"},
		{"strongpoison",""}
	}
}

CreatureTemplates:addCreatureTemplate(arachne_warrior, "arachne_warrior")