class WAttachment 
{
    string name;
    ref TStringArray fit;
    bool requireBattery;

    void WAttachment(string _name, ref TStringArray _fit, bool _requireBattery) 
    {
        name = _name;
        fit = _fit;
        requireBattery = _requireBattery;
    }
}

class WLoadout 
{
    string weapon;
    string ammo;

    void WLoadout(string _weapon, string _ammo)
    {
        weapon = _weapon;
        ammo = _ammo;
    }
}

class MissionConfigItems 
{
    static array<ref WAttachment> createMagazines() {
        ref array<ref WAttachment> magazines = new array<ref WAttachment>();

        magazines.Insert(new WAttachment("Mag_FNX45_15Rnd", {"FNX45"}, false));
        magazines.Insert(new WAttachment("Mag_Deagle_9rnd", {"Deagle", "Deagle_Gold"}, false));
        magazines.Insert(new WAttachment("Mag_Glock_15Rnd", {"Glock19"}, false));
        magazines.Insert(new WAttachment("Mag_CZ61_20Rnd", {"CZ61"}, false));
        magazines.Insert(new WAttachment("Mag_CZ75_15Rnd", {"CZ75"}, false));
        magazines.Insert(new WAttachment("Mag_IJ70_8Rnd", {"MakarovIJ70"}, false));
        magazines.Insert(new WAttachment("Mag_1911_7Rnd", {"Colt1911"}, false));
        magazines.Insert(new WAttachment("Mag_UMP_25Rnd", {"UMP45"}, false));
        magazines.Insert(new WAttachment("Mag_MP5_30Rnd", {"MP5K"}, false));
        magazines.Insert(new WAttachment("Mag_FAL_20Rnd", {"FAL"}, false));
        magazines.Insert(new WAttachment("Mag_STANAG_30Rnd", {"M4A1", "M16A2"}, false));
        magazines.Insert(new WAttachment("Mag_STANAG_60Rnd", {"M4A1", "M16A2"}, false));
        magazines.Insert(new WAttachment("Mag_AK101_30Rnd", {"AK101"}, false));
        magazines.Insert(new WAttachment("Mag_AKM_30Rnd", {"AKM"}, false));
        magazines.Insert(new WAttachment("Mag_Aug_30Rnd", {"Aug", "AugShort"}, false));
        magazines.Insert(new WAttachment("Mag_FAMAS_25Rnd", {"FAMAS", "SawedoffFAMAS"}, false));
        magazines.Insert(new WAttachment("Mag_Saiga_8Rnd", {"Saiga"}, false));
        magazines.Insert(new WAttachment("Mag_Saiga_Drum20Rnd", {"Saiga"}, false));
        magazines.Insert(new WAttachment("Mag_AK74_30Rnd", {"AKS74U", "AK74", "AK47"}, false));
        magazines.Insert(new WAttachment("Mag_AK74_45Rnd", {"AKS74U", "AK74", "AK47"}, false));
        magazines.Insert(new WAttachment("Mag_VSS_10Rnd", {"ASVAL", "VSS"}, false));
        magazines.Insert(new WAttachment("Mag_SVD_10Rnd", {"SVD"}, false));
        magazines.Insert(new WAttachment("Mag_CZ527_5rnd", {"CZ527"}, false));
        magazines.Insert(new WAttachment("Mag_Ruger1022_30Rnd", {"Ruger1022"}, false));
        magazines.Insert(new WAttachment("Mag_Scout_5Rnd", {"Scout"}, false));
        magazines.Insert(new WAttachment("Mag_MKII_10Rnd", {"MKII"}, false));

        return magazines;
    }

    static array<ref WAttachment> createOptics() {
        ref array<ref WAttachment> optics = new array<ref WAttachment>();

        optics.Insert(new WAttachment("M4_T3NRDSOptic", {"M4A1", "Scout", "MP5K", "UMP45", "Aug", "FAL" }, true));  //OK
        optics.Insert(new WAttachment("ACOGOptic", {"M4A1", "Scout", "MP5K", "ASVAL", "UMP45", "FAL", "Aug"}, false)); //OK, @TODO add pioneer
        optics.Insert(new WAttachment("ACOGOptic_6x", {"UMP45", "Scout", "MP5K", "M4A1", "FAL", "ASVAL"}, false)); //OK
        optics.Insert(new WAttachment("PUScopeOptic", {"Mosin9130", "SKS"}, false)); //OK
        optics.Insert(new WAttachment("HuntingOptic", {"B95", "Ruger1022", "Repeater", "Winchester70", "CZ527", "Colt1911"}, false)); //OK
        optics.Insert(new WAttachment("KashtanOptic", {"AKM", "AK74", "AK101", "Saiga", "SVD", "VSS"}, false)); //OK P1-87-L
        optics.Insert(new WAttachment("KobraOptic", {"AKM","AK101", "AK74"}, true)); //OK
        optics.Insert(new WAttachment("M4_CarryHandleOptic", {"M4A1"}, false)); //OK
        optics.Insert(new WAttachment("M68Optic", {"MP5K", "Scout", "UMP45", "M4A1", "FAL", "ASVAL"}, true)); //OK combat sight @TODO add pioneer
        optics.Insert(new WAttachment("PSO11Optic", {"AKM", "AK74", "AK101", "Saiga", "SVD", "VSS"}, true));  //OK
        optics.Insert(new WAttachment("PSO1Optic", {"AKM", "AK74", "AK101", "Saiga", "SVD", "VSS"}, true)); //OK
        //new WAttachment("PistolOptic", {"Glock19", "CZ75", "FNX45", "Deagle", "Golden_Deagle", "Mp133Shotgun"}, true), // ????
        optics.Insert(new WAttachment("PistolOptic", {"Deagle", "Golden_Deagle"}, true));  //OK Pistol Scope
        optics.Insert(new WAttachment("ReflexOptic", {"MP5K", "UMP45", "M4A1", "FAL", "ASVAL", "Aug"}, true)); //OK
        optics.Insert(new WAttachment("FNP45_MRDSOptic", {"FNX45"}, true)); //OK
        optics.Insert(new WAttachment("BUISOptic", {"M4A1", "MP5K","UMP45", "Aug", "FAL"}, false));

        return optics;
    }

    static array<ref WAttachment> createButtstocks() {
        ref array<ref WAttachment> buttstocks = new array<ref WAttachment>();

        buttstocks.Insert(new WAttachment("M4_CQBBttstck_Black", {"M4A1"}, false));
        buttstocks.Insert(new WAttachment("M4_MPBttstck", {"M4A1"}, false));
        buttstocks.Insert(new WAttachment("AK_WoodBttstck", {"AKM"}, false));
        buttstocks.Insert(new WAttachment("AK_PlasticBttstck", {"AKM", "AK101",}, false));
        buttstocks.Insert(new WAttachment("AK_FoldingBttstck_Black", {"AK74"}, false));
        buttstocks.Insert(new WAttachment("AKS74U_Bttstck", {"AKS74U"}, false));
        buttstocks.Insert(new WAttachment("AK74_WoodBttstck", {"AK74", "AK101"}, false));
        
        buttstocks.Insert(new WAttachment("Saiga_Bttstck", {"Saiga"}, false));
        buttstocks.Insert(new WAttachment("MP5k_StockBttstck", {"MP5K"}, false));
        buttstocks.Insert(new WAttachment("Fal_FoldingBttstck", {"FAL"}, false));
        buttstocks.Insert(new WAttachment("Fal_OeBttstck", {"FAL"}, false));

        return buttstocks;
    }

    static array<ref WAttachment> createHandAttachments() {
        ref array<ref WAttachment> handAttachments = new array<ref WAttachment>();
        //M4
        handAttachments.Insert(new WAttachment("M4_RISHndgrd_Black", {"M4A1"}, false));
        handAttachments.Insert(new WAttachment("M4_PlasticHndgrd", {"M4A1"}, false));
        handAttachments.Insert(new WAttachment("M4_MPHndgrd",  {"M4A1"}, false));
        //MP5
        handAttachments.Insert(new WAttachment("MP5_PlasticHndgrd", {"MP5K"}, false));
        handAttachments.Insert(new WAttachment("MP5_RailHndgrd", {"MP5K"}, false));
        //AK
        handAttachments.Insert(new WAttachment("AK_WoodHndgrd", {"AKM"}, false));
        handAttachments.Insert(new WAttachment("AK74_Hndgrd", {"AK74"}, false));
        handAttachments.Insert(new WAttachment("AK_PlasticHndgrd", {"AKM", "AK101", "AK74"}, false));
        handAttachments.Insert(new WAttachment("AK_RailHndgrd", {"AKM", "AK101", "AK74"}, false));
        
        return handAttachments;
    }

    static array<ref WAttachment> createBarrelAttachments() {
        ref array<ref WAttachment> barrelAttachments = new array<ref WAttachment>();
        barrelAttachments.Insert(new WAttachment("Mosin_Compensator", {"Mosin9130"}, false)); //OK
        barrelAttachments.Insert(new WAttachment("MP5_Compensator", {"MP5K"}, false)); //OK
        barrelAttachments.Insert(new WAttachment("M4_Suppressor", {"M4A1"}, false)); //OK
        barrelAttachments.Insert(new WAttachment("MakarovPBSuppressor", {"MakarovIJ70"}, false)); //OK
        barrelAttachments.Insert(new WAttachment("AK_Suppressor", {"AKM", "AK101", "AK74", "AKS74U", "VSD"}, false)); //OK
        barrelAttachments.Insert(new WAttachment("PistolSuppressor", {"MP5K", "UMP45", "FNX45", "CZ75", "CZ61", "Glock19", "Deagle", "Deagle_Gold"}, false)); //OK
        barrelAttachments.Insert(new WAttachment("ImprovisedSuppressor", {"MP5K", "AugShort", "UMP45", "AK74", "AKS74U", "AK101", "M4A1", "M16A2", "SawedoffFAMAS", "FAMAS", "CZ527", "SKS", "Mosin9130", "Winchester70", "SVD", "MakarovIJ70", "Glock19", "CZ75", "Colt1911", "FNX45", "Deagle", "Golden_Deagle"}, false)); //OK @TODO add pioneer
        return barrelAttachments;
    }

    static array<ref WLoadout> createSecondaryLoadouts() {
        ref array<ref WLoadout> secondaryLoadouts = new array<ref WLoadout>();
        //Pew pews
        secondaryLoadouts.Insert(new WLoadout("FNX45", "Ammo_45ACP"));
        secondaryLoadouts.Insert(new WLoadout("MakarovIJ70", "Ammo_380"));
        secondaryLoadouts.Insert(new WLoadout("CZ61", "Ammo_380"));
        secondaryLoadouts.Insert(new WLoadout("CZ75", "Ammo_9x19"));
        secondaryLoadouts.Insert(new WLoadout("Deagle_Gold", "Ammo_357"));
        secondaryLoadouts.Insert(new WLoadout("Glock19", "Ammo_9x19"));
        secondaryLoadouts.Insert(new WLoadout("Colt1911", "Ammo_45ACP"));
        secondaryLoadouts.Insert(new WLoadout("Magnum", "Ammo_357"));
        secondaryLoadouts.Insert(new WLoadout("MKII", "Ammo_22"));
        
        return secondaryLoadouts;
    }

    static array<ref WLoadout> createLoadouts() {
        autoptr array<ref WLoadout> loadouts = new array<ref WLoadout>();
        //SMGs 
        loadouts.Insert(new WLoadout("MP5K", "Ammo_9x19")); 
        loadouts.Insert(new WLoadout("UMP45","Ammo_45ACP"));
        //Rifles
        loadouts.Insert(new WLoadout("AKM", "Ammo_762x39"));
        loadouts.Insert(new WLoadout("AK101", "Ammo_556x45"));
        loadouts.Insert(new WLoadout("AK74", "Ammo_545x39"));
        loadouts.Insert(new WLoadout("AKS74U", "Ammo_545x39"));
        loadouts.Insert(new WLoadout("Aug", "Ammo_556x45"));
        loadouts.Insert(new WLoadout("AugShort", "Ammo_556x45"));
        loadouts.Insert(new WLoadout("M4A1", "Ammo_556x45"));
        loadouts.Insert(new WLoadout("M16A2", "Ammo_556x45"));
        loadouts.Insert(new WLoadout("FAL", "Ammo_308Win"));
        loadouts.Insert(new WLoadout("FAMAS", "Ammo_556x45"));
        loadouts.Insert(new WLoadout("SawedoffFAMAS", "Ammo_556x45"));
        //Troll guns
        loadouts.Insert(new WLoadout("ASVAL", "Ammo_9x39"));
        loadouts.Insert(new WLoadout("VSS", "Ammo_9x39"));
        loadouts.Insert(new WLoadout("Ruger1022", "Ammo_22")); //Sporter
        loadouts.Insert(new WLoadout("Scout", "Ammo_556x45"));
        //Snipers
        loadouts.Insert(new WLoadout("izh18", "Ammo_762x39"));
        loadouts.Insert(new WLoadout("Mosin9130", "Ammo_762x54"));
        loadouts.Insert(new WLoadout("CZ527", "Ammo_762x39"));
        loadouts.Insert(new WLoadout("SKS", "Ammo_762x39"));
        loadouts.Insert(new WLoadout("SVD", "Ammo_762x54"));
        loadouts.Insert(new WLoadout("Winchester70", "Ammo_308Win")); //TUNDRA
        loadouts.Insert(new WLoadout("B95", "Ammo_308Win")); //BLAZE
        loadouts.Insert(new WLoadout("Repeater", "Ammo_357"));
        //Shotguns
        loadouts.Insert(new WLoadout("Izh43Shotgun", "Ammo_12gaPellets"));
        loadouts.Insert(new WLoadout("Mp133Shotgun", "Ammo_12gaPellets"));
        loadouts.Insert(new WLoadout("Saiga", "Ammo_12gaPellets")); 

        return loadouts;
    }
}