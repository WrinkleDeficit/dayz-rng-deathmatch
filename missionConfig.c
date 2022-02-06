
class MissionConfig 
{
    /*
    *   Command prefix
    */
    static const string COMMAND_PREFIX = "/";
    /*
    *   How long each player area will play before automatically changing to next available
    */
    static const int MAP_INTERVAL_MINUTES = 10;
    /*
    *   @TODO explain map buffer size
    */
    static const int MAP_BUFFER_PERCENTAGE = 60;
    /*
    *   How often player positions are to be checked. 
    *   Please note that player will receive a message every check 
    *   if they are outside the intended play area. So very short intervals will cause unwanted spam.
    */
    static const int POSITION_CHECK_INTERVAL_SECONDS = 5;
    /*
    *   How many player positions will be checked per tick
    *
    *   Eg. Server has 10 players and the value is 5, it takes two ticks to check every player
    */
    static const int POSITION_CHECKS_PER_TICK = 5;
    /*
    *   How many magazines players get
    */
    static const int MAG_COUNT = 4;

    static ref const array<ref DmLocation> locations = MissionConfigLocations.createLocations();
    static ref const array<ref WAttachment> magazines = MissionConfigItems.createMagazines();
    static ref const array<ref WAttachment> optics = MissionConfigItems.createOptics();
    static ref const array<ref WAttachment> buttstocks = MissionConfigItems.createButtstocks();
    static ref const array<ref WAttachment> handAttachments = MissionConfigItems.createHandAttachments();
    static ref const array<ref WAttachment> barrelAttachments = MissionConfigItems.createBarrelAttachments();
    static ref const array<ref WLoadout> loadouts = MissionConfigItems.createLoadouts();
    static ref const array<ref WLoadout> secondaryLoadouts = MissionConfigItems.createSecondaryLoadouts();

    static ref const TStringArray shirts = 
    {
        "Hoodie_Red",
        "Hoodie_Green",
        "TTsKOJacket_Camo",
        "GorkaEJacket_Autumn","GorkaEJacket_Summer",
        "HikingJacket_Blue",
        "HikingJacket_Green",
        "HuntingJacket_Brown",
        "HuntingJacket_Autumn",
        "LeatherJacket_Black",
        "M65Jacket_Olive",
        "NBCJacketYellow",
        "ParamedicJacket_Crimson",
        "PoliceJacket",
        "HikingJacket_Black"
    };

    static ref const TStringArray helmets = 
    {
        "PumpkinHelmet",
        "NBCHoodYellow",
        "WitchHat",
        "SantasHat",
        "OfficerHat",
        "LeatherHat_Natural",
        "CowboyHat_darkBrown",
        "ZSh3PilotHelmet",
        "Mich2001Helmet",
        "HockeyHelmet_White",
        "GorkaHelmet",
        "FirefightersHelmet_Yellow",
        "DirtBikeHelmet_Red",
        "DirtBikeHelmet_Chernarus",
        "ConstructionHelmet_White",
        "FlatCap_Brown",
        "BeanieHat_Pink",
        "BallisticHelmet_UN",
        "BallisticHelmet_Green",
        "BallisticHelmet_Black",
        "BoonieHat_Olive",
        "CowboyHat_Brown",
        "PrisonerCap",
        "Ssh68Helmet",
        "BallisticHelmet_Black",
        "BallisticHelmet_UN"
    };

    static ref const TStringArray pants = 
    {
        "CanvasPantsMidi_Beige",
        "BDUPants",
        "USMCPants_Desert",
        "USMCPants_Woodland",
        "TrackSuitPants_Red",
        "TrackSuitPants_Blue",
        "TTSKOPants",
        "Skirt_White",
        "Skirt_Yellow",
        "SlacksPants_Beige",
        "ShortJeans_Red",
        "ShortJeans_Black",
        "Jeans_Black",
        "Jeans_BlueDark",
        "Jeans_Blue",
        "Jeans_Brown",
        "Jeans_Green",
        "Jeans_Grey"
    };

    static ref const TStringArray shoes = 
    {
        "Wellies_Black",
        "Wellies_Green",
        "Wellies_Brown",
        "TTSKOBoots",
        "MilitaryBoots_Redpunk",
        "NBCBootsYellow",
        "MilitaryBoots_Black",
        "MilitaryBoots_Beige",
        "CombatBoots_Black",
        "CombatBoots_Beige",
        "AthleticShoes_Black",
        "AthleticShoes_Brown",
        "AthleticShoes_Grey",
        "HikingBootsLow_Beige",
        "HikingBootsLow_Black",
        "HikingBootsLow_Grey",
        "HikingBoots_Black"
    };

    static ref const TStringArray gloves = 
    {
        "WorkingGloves_Yellow",
        "WorkingGloves_Brown",
        "WorkingGloves_Beige",
        "WorkingGloves_Black",
        "TacticalGloves_Green",
        "TacticalGloves_Black",
        "TacticalGloves_Beige",
        "SurgicalGloves_White",
        "SurgicalGloves_Green",
        "SurgicalGloves_Blue",
        "OMNOGloves_Gray",
        "OMNOGloves_Brown",
        "LeatherGloves_Beige",
        "LeatherGloves_Black",
        "LeatherGloves_Natural",
        "NBCGlovesGray",
        "NBCGlovesYellow"
    };

    static ref const TStringArray backpacks = {
        "MountainBag_Red",
        "MountainBag_Orange",
        "MountainBag_Green",
        "MountainBag_Blue",
        "TortillaBag",
        "HuntingBag",
        "AssaultBag_Ttsko",
        "AssaultBag_Black",
        "AssaultBag_Green",
        "CoyoteBag_Brown",
        "CoyoteBag_Green",
        "AliceBag_Green",
        "AliceBag_Black",
        "AliceBag_Camo"
    };

    static ref const TStringArray vests = 
    {
        "ReflexVest",
        "HuntingVest",
        "UKAssVest_Olive",
        "UKAssVest_Khaki",
        "UKAssVest_Camo",
        "UKAssVest_Black",
        "PlateCarrierComplete","PlateCarrierVest",
        "HighCapacityVest_Olive","HighCapacityVest_Black",
        "BallisticVest",
        "PressVest_LightBlue",
        "PressVest_Blue",
        "PoliceVest"
    };

    static ref const TStringArray tools = 
    {
        "Knife",
        "CombatKnife",
        "StoneKnife",
        "KitchenKnife",
        "HuntingKnife"
    };

    static ref const TStringArray masks = 
    {
        "Bandana_Blackpattern",
        "HoxtonMask",
        "HockeyMask",
        "GasMask",
        "GP5GasMask",
        "DallasMask",
        "Bandana_Redpattern",
        "Bandana_Polkapattern",
        "Bandana_Greenpattern",
        "Bandana_Camopattern",
        "BandanaMask_RedPattern",
        "BandanaMask_PolkaPattern",
        "BandanaMask_GreenPattern",
        "BandanaMask_CamoPattern",
        "BandanaMask_BlackPattern",
        "Bandana_Blackpattern",
        "NioshFaceMask",
        "BandanaMask_RedPattern",
        "BandanaMask_GreenPattern",
        "BandanaMask_CamoPattern","BandanaMask_PolkaPattern",
        "BandanaMask_BlackPattern",
        "SurgicalMask","BalaclavaMask_White",
        "WolfMask",
        "AirborneMask","BalaclavaMask_Pink",
        "BalaclavaMask_Green",
        "BalaclavaMask_Beige","BalaclavaMask_Black",
        "BalaclavaMask_Blackskull","BalaclavaMask_Blue"
    };

    static ref const TStringArray nades = 
    {
        "LandMineTrap",
        "RGD5Grenade",
        "RDG2SmokeGrenade_White",
        "RDG2SmokeGrenade_Black",
        "M18SmokeGrenade_Yellow",
        "M67Grenade",
        "M18SmokeGrenade_Green",
        "M18SmokeGrenade_White",
        "M18SmokeGrenade_Red",
        "M18SmokeGrenade_Purple",
        "FlashGrenade"
    };

    static ref const TStringArray medical = 
    {
        "BandageDressing",
        "BandageDressing",
        "BandageDressing",
        "PainkillerTablets",
        "Morphine"
    };
}