#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\missionConfigLocations.c";
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\missionConfigItems.c";
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\missionConfig.c";

class TIntBuffer
{
    private int bufferSize;
    private ref TIntArray items;
    
    void TIntBuffer(int _bufferSize, TIntArray _items)
    {
        bufferSize = _bufferSize;
        items = _items;
    }

    int Find(int item)
    {
        return items.Find(item);
    }

    void Add(int item)
    {
        items.Insert(item);

        if(items.Count() > bufferSize)
        {
            items.Remove(0);
        }
    }
}

/*
*
*  
*/
class MissionHelper
{
    /*
    *   Transforms 2D map coordinates to 3D vector where .y (index 1) will be valid surface height at the given position
    */
    static vector getSurfaceCoordinates(Vector2 pos2D)
    {
        /*
        *   String interpolation, do you speak it?
        *   vector v = x + " 10 " + y === invalid syntax grape
        */
        vector pos3D;
        pos3D[0] = pos2D.x;
        pos3D[1] = GetGame().SurfaceY(pos2D.x, pos2D.y) + 0.1;
        pos3D[2] = pos2D.y;
        return pos3D;
    }
    /*
    *   Send message to player
    *   Generic pasta from somewhere
    */
    static void messagePlayer(PlayerBase player, string message) 
    {
        Param1<string> msgParam = new Param1<string>(message);
        GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, msgParam, true, player.GetIdentity());
    }
    /*
    *   Send message to player all players
    */
    static void messagePlayers(string message)
    {
        array<Man> players = new array<Man>;
        GetGame().GetPlayers(players);

        int i = -1;
        while(++i < players.Count()) 
        {
            messagePlayer(PlayerBase.Cast(players[i]), message);
        }
    }

    static array<ref WAttachment> findAvailableAttachments(string weaponName, array<ref WAttachment> attachments) 
    {
        ref array<ref WAttachment> ret = new array<ref WAttachment>();
        int i = -1;

        while(++i < attachments.Count())
        {
            int j = -1;
            while(++j < attachments[i].fit.Count())
            {
                if(attachments[i].fit[j] == weaponName) 
                {
                    autoptr WAttachment found = attachments[i];
                    ret.Insert(new WAttachment(found.name, found.fit, found.requireBattery));
                }
            }
        }

        return ret;
    }

    static WAttachment getRandomAttachment(int chance, string weaponName, array<ref WAttachment> availableAttachments) 
    {
        if(Math.RandomInt(0, 100) > chance) 
        {
            return NULL;
        }

        ref array<autoptr WAttachment> attachments = findAvailableAttachments(weaponName, availableAttachments);

        WAttachment ret = NULL;
        if(attachments.Count() > 0)
        {
            int rngIdx = Math.RandomInt(0, attachments.Count() - 1);
            ret = new WAttachment(attachments[rngIdx].name, attachments[rngIdx].fit, attachments[rngIdx].requireBattery);
        }

        delete attachments;
        return ret;
    }
    
    static EntityAI armWeapon(PlayerBase player, WLoadout wLoadout)
    {
        ref array<ref WAttachment> attachments = new array<ref WAttachment>();
        attachments.Insert(getRandomAttachment(80, wLoadout.weapon, MissionConfig.optics));
        attachments.Insert(getRandomAttachment(80, wLoadout.weapon, MissionConfig.handAttachments));
        attachments.Insert(getRandomAttachment(90, wLoadout.weapon, MissionConfig.buttstocks));
        attachments.Insert(getRandomAttachment(25, wLoadout.weapon, MissionConfig.barrelAttachments));

        EntityAI weapon = player.GetInventory().CreateInInventory(wLoadout.weapon);

        int i = -1;
        while(++i < attachments.Count())
        {  
            if(attachments[i] != NULL) {
                EntityAI created = weapon.GetInventory().CreateAttachment(attachments[i].name);

                if(created != null && attachments[i].requireBattery)
                {
                    created.GetInventory().CreateAttachment("Battery9V");
                }
            }
        }

        autoptr WAttachment mag = getRandomAttachment(100, wLoadout.weapon, MissionConfig.magazines);
 
        if(mag != null) 
        {
            i = -1;
            while(++i < MissionConfig.MAG_COUNT - 1) 
            {
                player.GetInventory().CreateInInventory(mag.name);
            }

            weapon.GetInventory().CreateAttachment(mag.name);
        }

        if(wLoadout.ammo != "") 
        {
            ItemBase ammoItem;
            i = -1;
            while(++i < 5) 
            {
                ammoItem = ItemBase.Cast(player.GetInventory().CreateInInventory(wLoadout.ammo));
                ammoItem.SetQuantity(20);
            }
        }

        delete attachments;
        return weapon;
    }

    static void handlePlayer(PlayerBase player) 
    {
        //Clear inv
        player.RemoveAllItems();

        //Clothing
        player.GetInventory().CreateInInventory(MissionConfig.helmets.GetRandomElement());
        player.GetInventory().CreateInInventory(MissionConfig.vests.GetRandomElement());
        player.GetInventory().CreateInInventory(MissionConfig.shirts.GetRandomElement());
        player.GetInventory().CreateInInventory(MissionConfig.pants.GetRandomElement());
        player.GetInventory().CreateInInventory(MissionConfig.shoes.GetRandomElement());
        player.GetInventory().CreateInInventory(MissionConfig.gloves.GetRandomElement());
        player.GetInventory().CreateInInventory(MissionConfig.backpacks.GetRandomElement());
        player.GetInventory().CreateInInventory(MissionConfig.tools.GetRandomElement());

        //Mask
        if(Math.RandomInt(0, 100) < 80) 
        {   
            player.GetInventory().CreateInInventory(MissionConfig.masks.GetRandomElement());
        }
        
        //Healing items 
        int i = -1;
        while(++i < MissionConfig.medical.Count())
        {
            ItemBase item = ItemBase.Cast(player.GetInventory().CreateInInventory(MissionConfig.medical[i]));
            if(i == 1) {
                player.SetQuickBarEntityShortcut(item, 2, true);
            }
        }

        //Main weapon
        WLoadout mainLoadout = MissionConfig.loadouts.GetRandomElement();
        EntityAI primary = armWeapon(player, mainLoadout);

        //Secondary weapon
        WLoadout secondaryLoadout = MissionConfig.secondaryLoadouts.GetRandomElement();
        EntityAI secondary = armWeapon(player, secondaryLoadout);

        //player.LocalTakeEntityToHands(primary);
        ItemBase nade = ItemBase.Cast(player.GetInventory().CreateInInventory(MissionConfig.nades.GetRandomElement()));

        player.SetQuickBarEntityShortcut(primary, 0, true);
        player.SetQuickBarEntityShortcut(secondary, 1, true);
        player.SetQuickBarEntityShortcut(nade, 3, true);
    }
}

class CustomMission : MissionServer 
{
    /*
    *   If deathmatch is paused (paused = regular survival)
    */
    bool isPaused = false;
    /*
    *   Pause time elapsed (seconds)
    */
    float pausetimeElapsed = 0;
    /*
    *   Maptime "timestamp" (seconds) when the last message was sent informing players about active pause
    */
    float pauseMessageSent = 0;
    /*
    *   Index of the current play area
    */
    int locationIdx = Math.RandomInt(0, MissionConfig.locations.Count());
    /*
    *   Past locations in buffer
    */
    ref TIntBuffer pastLocationBuffer = new TIntBuffer(MissionConfig.locations.Count() * (MissionConfig.MAP_BUFFER_PERCENTAGE * 0.01), { locationIdx });
    /*
    *   How long the current play area has been in use (seconds)
    */
    float maptimeElapsed = 0;
    /*
    *   Maptime "timestamp" (seconds) when the last message was sent informing players about the upcoming change of play area
    */
    float changeMessageSent = 0;
    /*
    *   Maptime "timestamp" (seconds) when the last position check was initiated
    */
    float lastPositionCheck = 0;
    /*
    *   If position check is in progress
    */
    bool positionCheckInProgress = true;
    /*
    *   Current player index
    */
    int positionCheckIndex = 0;
    /*
    *   Ensure players are within the current zone
    */
    bool ensurePlayerLocations()
    {
        array<Man> players = new array<Man>;
        GetGame().GetPlayers(players);

        PlayerBase currentPlayer;

        int i = -1;
        while(++i < MissionConfig.POSITION_CHECKS_PER_TICK)
        {
            if(positionCheckIndex >= players.Count())
            {
                return false;
            }

            currentPlayer = PlayerBase.Cast(players[positionCheckIndex]);
            float health = currentPlayer.GetHealth("","");
            /*
            * Ignore dead players.
            * Syntax documentation had no mentions of 'continue' statement so here we go...
            * I'm too lazy to test if it exists
            */
            if(health > 0) 
            {
                vector playerPosition = currentPlayer.GetPosition();
                Vector2 cartoonPos = new Vector2(playerPosition[0], playerPosition[2]);
                DmLocationRadius currentRadius = MissionConfig.locations[locationIdx].isInLocation(cartoonPos);
                
                //Player is outside the playzone
                if(currentRadius == DmLocationRadius.Outside)
                {
                    MissionHelper.messagePlayer(currentPlayer, "YOU ARE TOO FAR FROM " + MissionConfig.locations[locationIdx].name);
                    //Kill player if in vehicle
                    if(currentPlayer.GetCommand_Vehicle()) 
                    {
                        currentPlayer.SetHealth("", "", -100);
                    }
                    //Otherwise teleport player to random spawn in current playarea
                    else
                    {
                        vector newPos = MissionHelper.getSurfaceCoordinates(MissionConfig.locations[locationIdx].positions.GetRandomElement());
                        currentPlayer.SetPosition(newPos);
                    }
                }
                //Player is within warning radius, far away from the limits
                else if(currentRadius == DmLocationRadius.Warn)
                {
                    MissionHelper.messagePlayer(currentPlayer, "LEAVING MATCH AREA. HEAD TOWARDS " + MissionConfig.locations[locationIdx].name);
                }
            }

            ++positionCheckIndex;
        }
        return true;
    }
    /*
    *   Apparently timeslice is seconds 
    */
    override void TickScheduler(float timeslice) 
    {
        //Too lazy to check if anything important happens on tick so just call super just to be sure.
        super.TickScheduler(timeslice);

        //If deathmatch is paused, send message informing about the pause every minute.
        if(isPaused)
        {
            pausetimeElapsed += timeslice;
            if ((pausetimeElapsed - pauseMessageSent) >= 60)
            {
                pauseMessageSent = pausetimeElapsed;
                MissionHelper.messagePlayers("[i] Deathmatch has been paused for "+ pausetimeElapsed + " seconds. Use '" + MissionConfig.COMMAND_PREFIX + "continue' to unpause...");
            }

            return;
        }

        //How many seconds the current location has been in use
        maptimeElapsed += timeslice;

        int maptimeSeconds = MissionConfig.MAP_INTERVAL_MINUTES * 60;
        //If "map time" exceeded
        if(maptimeElapsed > maptimeSeconds)
        {
            if(MissionConfig.locations.Count() > 1)
            {
                TIntArray useLocations = new TIntArray();
                int i = -1;
                while(++i < MissionConfig.locations.Count())
                {
                    if(i != locationIdx && pastLocationBuffer.Find(i) < 0)
                    {
                        useLocations.Insert(i);
                    }
                }

                locationIdx = useLocations.GetRandomElement();
                pastLocationBuffer.Add(locationIdx);

                MissionHelper.messagePlayers("Play area was changed to " + MissionConfig.locations[locationIdx].name + ".");
            }
            else
            {
                MissionHelper.messagePlayers("No other configured areas!");
            }

            //Reset elapsed map time
            maptimeElapsed = 0;
            //Reset last change message timestamp
            changeMessageSent = 0;
            //Disable current position check cycle (will be reset below). Will be processed next tick
            positionCheckInProgress = false;
            lastPositionCheck = -1 * MissionConfig.POSITION_CHECK_INTERVAL_SECONDS;
        }
        else if ((maptimeElapsed - changeMessageSent) >= 60)
        {
            float secondsUntilRestart = maptimeSeconds - maptimeElapsed;
            int minutes = Math.Floor(secondsUntilRestart / 60);
            int seconds = Math.Floor(secondsUntilRestart - (minutes * 60));

            MissionHelper.messagePlayers("Play area will change in " + minutes + " minutes and " + seconds + " seconds.");
            changeMessageSent = maptimeElapsed;
        }
        
        //Check player positions for virgin campers and players left in last location every once in a while and after every location change
        if(positionCheckInProgress)
        {
            positionCheckInProgress = ensurePlayerLocations();
        }
        //Reset position check variables on play area change and when current position check expires
        else if((maptimeElapsed - lastPositionCheck) > MissionConfig.POSITION_CHECK_INTERVAL_SECONDS)
        {
            lastPositionCheck = maptimeElapsed;
            positionCheckInProgress = true;
            positionCheckIndex = 0;
        }
    }
    /*
    *   On event, currently used for command handling
    */
    override void OnEvent(EventType eventTypeId, Param params) 
    {
        super.OnEvent(eventTypeId, params);

        if(eventTypeId == ChatMessageEventTypeID || eventTypeId == ChatChannelEventTypeID)
        { 
            ChatMessageEventParams msgParams = ChatMessageEventParams.Cast(params);
            string message = msgParams.param3; 

            if(msgParams.param1 == 0 && msgParams != "" && message.IndexOf(MissionConfig.COMMAND_PREFIX) == 0)
            {
                string command = message.Substring(1, message.Length() - 1);
                switch(command) 
                {
                    case "continue":
                        MissionHelper.messagePlayers("Deathmatch will continue!");
                        isPaused = false;
                        break;

                    case "pause":
                        MissionHelper.messagePlayers("Deathmatch will be paused!");
                        isPaused = true;
                        pausetimeElapsed = 0;
                        pauseMessageSent = 0;
                        break;

                    case "next":
                        MissionHelper.messagePlayers("Play area will change next tick!");
                        maptimeElapsed = MissionConfig.MAP_INTERVAL_MINUTES * 60;
                        isPaused = false;
                        break;
                }
            } 
        }
    }

    /*
    *   Set player stats
    */
    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);
        player.GetStatEnergy().Set(5000);
        player.GetStatWater().Set(5000);
    }

    /*
    *   Player equipment
    */
    override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
    {
        MissionHelper.handlePlayer(player);        
    }

    /*
    *   Player spawning
    */
    override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
    {
        autoptr Vector2 pos2D = MissionConfig.locations[locationIdx].positions.GetRandomElement();

        Entity playerEnt = GetGame().CreatePlayer(identity, characterName, MissionHelper.getSurfaceCoordinates(pos2D), 5, "NONE");
        Class.CastTo(m_player, playerEnt);

        GetGame().SelectPlayer(identity, m_player);
        MissionHelper.messagePlayer(m_player, MissionConfig.locations[locationIdx].name);
 
        return m_player;
    }
}

Mission CreateCustomMission(string path) 
{
    return new CustomMission();
}

void main()
{
    Weather weather = g_Game.GetWeather();

    weather.MissionWeather(false); 
    weather.GetOvercast().Set(Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
    weather.GetRain().Set(0, 0, 1);
    weather.GetFog().Set(Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

    //Economy
    Hive ce = CreateHive();
    if(ce) 
        ce.InitOffline();

    //Date Reset
    int year, month, day, hour, minute;
    int reset_month = 9, reset_day = 20;
    GetGame().GetWorld().GetDate(year, month, day, hour, minute);
    //Always start with somewhat day
    GetGame().GetWorld().SetDate(year, month, day, 10, 00);
}