
class DmLocationLimits 
{
    float minX = 1000000;
    float minY = 1000000;
    float maxX = 0;
    float maxY = 0;
    ref Vector2 center;

    void DmLocationLimits(autoptr array<autoptr Vector2> _positions)
    {
        int i = -1;
        int count = _positions.Count();
        autoptr Vector2 sum = new Vector2(0, 0);

        while(++i < count)
        {
            float x = _positions[i].x;
            float y = _positions[i].y;

            sum.x = sum.x + x;
            sum.y = sum.y + y;

            if(x > maxX)
                maxX = x;
            if(x < minX)
                minX = x;
            if(y > maxY)
                maxY = y;
            if(y < minY)
                minY = y;
        }

        center = new Vector2(sum.x / count, sum.y / count);
    }
}

enum DmLocationRadius
{
    Outside = 0,
    Warn = 1,
    Inside = 2
}

class DmLocation 
{
    string name;
    ref array<ref Vector2> positions;
    ref DmLocationLimits limits;

    void DmLocation(string _name, ref array<ref Vector2> _positions)
    {
        name = _name;
        positions = _positions;
        limits = new DmLocationLimits(_positions);
    }

    DmLocationRadius isInLocation(Vector2 position)
    {
        float tolerance = 150;
        float warnTolerance = tolerance / 2;

        if(position.x > (limits.maxX + tolerance) || (position.x < (limits.minX - tolerance))) 
        {
            return DmLocationRadius.Outside;
        }
        else if(position.y > (limits.maxY + tolerance) || (position.y < (limits.minY - tolerance)))
        {
            return DmLocationRadius.Outside;
        } 
        else if(position.x > (limits.maxX + warnTolerance) || (position.x < (limits.minX - warnTolerance)))
        {
            return DmLocationRadius.Warn;
        }
        else if(position.y > (limits.maxY + warnTolerance) || (position.y < limits.minY - warnTolerance))
        {
            return DmLocationRadius.Warn;
        }

        return DmLocationRadius.Inside;
    }
}

class MissionConfigLocations {
    static array<ref DmLocation> createLocations()
    {
        autoptr array<ref DmLocation> locations = new array<ref DmLocation>();

        autoptr array<ref Vector2> prisonPositions = new array<ref Vector2>();
        prisonPositions.Insert(new Vector2(2588.84, 1370.31));
        prisonPositions.Insert(new Vector2(2565.03, 1329.00));
        prisonPositions.Insert(new Vector2(2636.48, 1364.00));
        prisonPositions.Insert(new Vector2(2609.26, 1323.16));
        prisonPositions.Insert(new Vector2(2566.48, 1311.50));
        prisonPositions.Insert(new Vector2(2583.50, 1296.91));
        prisonPositions.Insert(new Vector2(2624.33, 1320.73));
        prisonPositions.Insert(new Vector2(2649.12, 1316.84));
        prisonPositions.Insert(new Vector2(2730.78, 1300.80));
        prisonPositions.Insert(new Vector2(2731.76, 1281.36));
        prisonPositions.Insert(new Vector2(2749.74, 1257.05));
        prisonPositions.Insert(new Vector2(2779.88, 1263.86));
        locations.Insert(new DmLocation("Prison island", prisonPositions));
        
        autoptr array<ref Vector2> balotaPositions = new array<ref Vector2>();
        balotaPositions.Insert(new Vector2(4916, 2603));
        balotaPositions.Insert(new Vector2(4811, 2548));
        balotaPositions.Insert(new Vector2(4860, 2435));
        balotaPositions.Insert(new Vector2(4902, 2375));
        balotaPositions.Insert(new Vector2(4998, 2322));
        balotaPositions.Insert(new Vector2(5114, 2254));
        balotaPositions.Insert(new Vector2(5244, 2248));
        balotaPositions.Insert(new Vector2(5072, 2384));
        balotaPositions.Insert(new Vector2(5161, 2277));
        balotaPositions.Insert(new Vector2(4943, 2446));
        locations.Insert(new DmLocation("Airfield Balota", balotaPositions));

        autoptr array<ref Vector2> zelenoPositions = new array<ref Vector2>();
        zelenoPositions.Insert(new Vector2(2524.19, 5115.79));
        zelenoPositions.Insert(new Vector2(2373.02, 5057.45));
        zelenoPositions.Insert(new Vector2(2490.17, 5148.84));
        zelenoPositions.Insert(new Vector2(2343.36, 5098.29));
        zelenoPositions.Insert(new Vector2(2319.06, 5161.00));
        zelenoPositions.Insert(new Vector2(2336.56, 5224.19));
        zelenoPositions.Insert(new Vector2(2252.95, 5274.26));
        zelenoPositions.Insert(new Vector2(2128.02, 5181.41));
        zelenoPositions.Insert(new Vector2(2555.30, 4986.48));
        zelenoPositions.Insert(new Vector2(2490.65, 5150.79));
        zelenoPositions.Insert(new Vector2(2420.65, 5170.72));
        zelenoPositions.Insert(new Vector2(2572.32, 5186.76));
        zelenoPositions.Insert(new Vector2(2537.32, 5190.65));
        zelenoPositions.Insert(new Vector2(2273.85, 5177.04));
        zelenoPositions.Insert(new Vector2(2273.85, 5177.04));
        zelenoPositions.Insert(new Vector2(2509.12, 4986.48));
        zelenoPositions.Insert(new Vector2(2231.08, 5201.34));
        zelenoPositions.Insert(new Vector2(2175.18, 5285.93));
        zelenoPositions.Insert(new Vector2(2463.92, 5257.25));
        zelenoPositions.Insert(new Vector2(2271.91, 5063.77));
        locations.Insert(new DmLocation("Zelenogorsk Military", zelenoPositions));

        //Krasno airfiled
        autoptr array<ref Vector2> krasnoPositions = new array<ref Vector2>();
        krasnoPositions.Insert(new Vector2(12130.45, 12694.72));
        krasnoPositions.Insert(new Vector2(12194.13, 12668.47));
        krasnoPositions.Insert(new Vector2(12238.36, 12650.00));
        krasnoPositions.Insert(new Vector2(12097.88, 12634.93));
        krasnoPositions.Insert(new Vector2(12234.96, 12596.04));
        krasnoPositions.Insert(new Vector2(11853.37, 12596.53));
        krasnoPositions.Insert(new Vector2(11904.41, 12573.68));
        krasnoPositions.Insert(new Vector2(11953.02, 12553.75));
        krasnoPositions.Insert(new Vector2(11910.25, 12508.54));
        krasnoPositions.Insert(new Vector2(11931.63, 12433.68));
        krasnoPositions.Insert(new Vector2(12042.95, 12515.35));
        krasnoPositions.Insert(new Vector2(12182.46, 12597.98));
        krasnoPositions.Insert(new Vector2(11992.40, 12500.76));
        krasnoPositions.Insert(new Vector2(11795.04, 12594.10));
        locations.Insert(new DmLocation("Airfield Krasnostav", krasnoPositions));

        //Nagornoe
        autoptr array<ref Vector2> nagoPositions = new array<ref Vector2>();
        nagoPositions.Insert(new Vector2(9242.06, 14593.46));
        nagoPositions.Insert(new Vector2(9117.62, 14539.99));
        nagoPositions.Insert(new Vector2(9214.84, 14516.66));
        nagoPositions.Insert(new Vector2(9296.50, 14523.46));
        nagoPositions.Insert(new Vector2(9317.89, 14655.69));
        nagoPositions.Insert(new Vector2(9348.03, 14653.74));
        nagoPositions.Insert(new Vector2(9383.03, 14675.13));
        nagoPositions.Insert(new Vector2(9389.83, 14697.49));
        nagoPositions.Insert(new Vector2(9483.16, 14598.33));
        nagoPositions.Insert(new Vector2(9314.00, 14527.35));
        nagoPositions.Insert(new Vector2(9404.41, 14542.91));
        nagoPositions.Insert(new Vector2(9179.35, 14547.28));
        nagoPositions.Insert(new Vector2(9288.72, 14554.09));
        nagoPositions.Insert(new Vector2(9337.82, 14620.69));
        nagoPositions.Insert(new Vector2(9409.28, 14633.32));
        nagoPositions.Insert(new Vector2(9437.96, 14717.42));
        nagoPositions.Insert(new Vector2(9198.31, 14592.49));
        nagoPositions.Insert(new Vector2(9480.73, 14659.57));
        nagoPositions.Insert(new Vector2(9493.37, 14724.71));
        nagoPositions.Insert(new Vector2(9437.96, 14717.91));
        locations.Insert(new DmLocation("Nagornoe", nagoPositions));

        //Grishino
        autoptr array<ref Vector2> grishinoPositions = new array<ref Vector2>();
        grishinoPositions.Insert(new Vector2(5836.46, 10110.08));
        grishinoPositions.Insert(new Vector2(5827.22, 10192.72));
        grishinoPositions.Insert(new Vector2(5896.74, 10165.01));
        grishinoPositions.Insert(new Vector2(5878.26, 10267.09));
        grishinoPositions.Insert(new Vector2(5961.87, 10223.34));
        grishinoPositions.Insert(new Vector2(5911.81, 10301.60));
        grishinoPositions.Insert(new Vector2(6005.62, 10294.31));
        grishinoPositions.Insert(new Vector2(5966.25, 10397.85));
        grishinoPositions.Insert(new Vector2(6033.33, 10385.70));
        grishinoPositions.Insert(new Vector2(5999.30, 10466.88));
        grishinoPositions.Insert(new Vector2(6072.22, 10510.63));
        grishinoPositions.Insert(new Vector2(6061.04, 10564.10));
        grishinoPositions.Insert(new Vector2(6107.70, 10466.88));
        grishinoPositions.Insert(new Vector2(6159.72, 10451.81));
        grishinoPositions.Insert(new Vector2(6187.91, 10358.48));
        grishinoPositions.Insert(new Vector2(6131.04, 10260.28));
        grishinoPositions.Insert(new Vector2(5951.18, 10298.69));
        grishinoPositions.Insert(new Vector2(5817.99, 10152.37));
        locations.Insert(new DmLocation("Grishino", grishinoPositions));

        //Kamyshovo
        autoptr array<ref Vector2> kamyPositions = new array<ref Vector2>();
        kamyPositions.Insert(new Vector2(11973.93, 3817.39));
        kamyPositions.Insert(new Vector2(12018.16, 3743.50));
        kamyPositions.Insert(new Vector2(12055.59, 3647.74));
        kamyPositions.Insert(new Vector2(12055.59, 3647.74));
        kamyPositions.Insert(new Vector2(11979.27, 3567.04));
        kamyPositions.Insert(new Vector2(11866.50, 3456.70));
        kamyPositions.Insert(new Vector2(12028.85, 3481.49));
        kamyPositions.Insert(new Vector2(12048.30, 3527.67));
        kamyPositions.Insert(new Vector2(12147.95, 3498.02));
        kamyPositions.Insert(new Vector2(12293.29, 3516.49));
        kamyPositions.Insert(new Vector2(12286.97, 3480.52));
        kamyPositions.Insert(new Vector2(12072.60, 3425.59));
        kamyPositions.Insert(new Vector2(12087.19, 3380.38));
        kamyPositions.Insert(new Vector2(11905.39, 3418.29));
        kamyPositions.Insert(new Vector2(11958.86, 3519.89));
        kamyPositions.Insert(new Vector2(12023.99, 3481.49));
        kamyPositions.Insert(new Vector2(11991.42, 3525.72));
        kamyPositions.Insert(new Vector2(12011.84, 3482.46));
        kamyPositions.Insert(new Vector2(12154.75, 3498.50));
        kamyPositions.Insert(new Vector2(12112.46, 3549.06));
        kamyPositions.Insert(new Vector2(12197.53, 3543.71));
        locations.Insert(new DmLocation("Kamyshovo Horror", kamyPositions));

        //NEAF north
        autoptr array<ref Vector2> neafNPositions = new array<ref Vector2>();
        neafNPositions.Insert(new Vector2(3964.99, 11726.88));
        neafNPositions.Insert(new Vector2(3904.22, 11818.27));
        neafNPositions.Insert(new Vector2(4002.90, 11864.93));
        neafNPositions.Insert(new Vector2(4138.04, 11623.34));
        neafNPositions.Insert(new Vector2(4005.82, 11591.25));
        neafNPositions.Insert(new Vector2(4073.39, 11738.06));
        neafNPositions.Insert(new Vector2(4094.77, 11802.22));
        neafNPositions.Insert(new Vector2(4046.65, 11848.40));
        neafNPositions.Insert(new Vector2(4158.94, 11667.09));
        neafNPositions.Insert(new Vector2(4118.11, 11583.96));
        neafNPositions.Insert(new Vector2(4061.23, 11582.02));
        neafNPositions.Insert(new Vector2(3994.15, 11618.47));
        neafNPositions.Insert(new Vector2(4029.15, 11706.46));
        neafNPositions.Insert(new Vector2(4071.93, 11739.52));
        neafNPositions.Insert(new Vector2(3996.58, 11781.32));
        neafNPositions.Insert(new Vector2(4002.42, 11739.52));
        neafNPositions.Insert(new Vector2(4021.86, 11641.81));
        neafNPositions.Insert(new Vector2(4003.39, 11691.88));
        neafNPositions.Insert(new Vector2(4094.29, 11818.27));
        locations.Insert(new DmLocation("Bshnya (NEAF North)", neafNPositions));

        //NEAF south west
        autoptr array<ref Vector2> neafSWPositions = new array<ref Vector2>();
        neafSWPositions.Insert(new Vector2(4456.92, 9526.75));
        neafSWPositions.Insert(new Vector2(4467.12, 9578.27));
        neafSWPositions.Insert(new Vector2(4425.81, 9606.47));
        neafSWPositions.Insert(new Vector2(4453.51, 9690.56));
        neafSWPositions.Insert(new Vector2(4475.87, 9705.63));
        neafSWPositions.Insert(new Vector2(4522.54, 9709.04));
        neafSWPositions.Insert(new Vector2(4529.83, 9769.80));
        neafSWPositions.Insert(new Vector2(4588.65, 9783.41));
        neafSWPositions.Insert(new Vector2(4605.66, 9751.81));
        neafSWPositions.Insert(new Vector2(4630.94, 9726.05));
        neafSWPositions.Insert(new Vector2(4660.10, 9679.87));
        neafSWPositions.Insert(new Vector2(4670.31, 9655.56));
        neafSWPositions.Insert(new Vector2(4670.31, 9655.56));
        neafSWPositions.Insert(new Vector2(4729.62, 9611.81));
        neafSWPositions.Insert(new Vector2(4732.53, 9587.99));
        neafSWPositions.Insert(new Vector2(4679.06, 9535.98));
        neafSWPositions.Insert(new Vector2(4749.06, 9526.75));
        neafSWPositions.Insert(new Vector2(4665.45, 9530.15));
        neafSWPositions.Insert(new Vector2(4571.15, 9451.88));
        neafSWPositions.Insert(new Vector2(4568.23, 9518.48));
        neafSWPositions.Insert(new Vector2(4628.02, 9589.45));
        neafSWPositions.Insert(new Vector2(4681.49, 9609.38));
        neafSWPositions.Insert(new Vector2(4619.27, 9538.41));
        neafSWPositions.Insert(new Vector2(4523.51, 9614.73));
        neafSWPositions.Insert(new Vector2(4615.87, 9679.87));
        neafSWPositions.Insert(new Vector2(4491.92, 9623.97));
        locations.Insert(new DmLocation("NEAF South West", neafSWPositions));

        //NEAF south East
        autoptr array<ref Vector2> neafSEPositions = new array<ref Vector2>();
        neafSEPositions.Insert(new Vector2(5205.51, 9754.24));
        neafSEPositions.Insert(new Vector2(5264.81, 9846.12));
        neafSEPositions.Insert(new Vector2(5313.42, 9773.20));
        neafSEPositions.Insert(new Vector2(5255.09, 9879.17));
        neafSEPositions.Insert(new Vector2(5180.23, 9858.76));
        neafSEPositions.Insert(new Vector2(5200.16, 9898.62));
        neafSEPositions.Insert(new Vector2(5172.45, 9828.13));
        neafSEPositions.Insert(new Vector2(5172.94, 9786.33));
        neafSEPositions.Insert(new Vector2(5234.67, 9781.47));
        neafSEPositions.Insert(new Vector2(5293.49, 9857.79));
        neafSEPositions.Insert(new Vector2(5313.91, 9769.31));
        neafSEPositions.Insert(new Vector2(5240.99, 9879.66));
        neafSEPositions.Insert(new Vector2(5194.81, 9844.66));
        locations.Insert(new DmLocation("NEAF South East", neafSEPositions));

        //Train station Myshkino Timber
        autoptr array<ref Vector2> myshtiPositions = new array<ref Vector2>();
        myshtiPositions.Insert(new Vector2(915.21, 7743.21));
        myshtiPositions.Insert(new Vector2(919.10, 7750.99));
        myshtiPositions.Insert(new Vector2(925.42, 7588.14));
        myshtiPositions.Insert(new Vector2(896.74, 7581.34));
        myshtiPositions.Insert(new Vector2(917.64, 7548.28));
        myshtiPositions.Insert(new Vector2(1008.54, 7577.45));
        myshtiPositions.Insert(new Vector2(960.90, 7667.86));
        myshtiPositions.Insert(new Vector2(882.64, 7703.83));
        myshtiPositions.Insert(new Vector2(887.02, 7634.81));
        myshtiPositions.Insert(new Vector2(948.27, 7603.21));
        myshtiPositions.Insert(new Vector2(1022.15, 7651.82));
        myshtiPositions.Insert(new Vector2(917.16, 7752.93));
        myshtiPositions.Insert(new Vector2(940.49, 7650.36));
        myshtiPositions.Insert(new Vector2(923.96, 7651.33));
        myshtiPositions.Insert(new Vector2(1053.26, 7603.70));
        myshtiPositions.Insert(new Vector2(1004.17, 7698.49));
        myshtiPositions.Insert(new Vector2(905.49, 7649.39));
        locations.Insert(new DmLocation("Myshkino Timber Train Station", myshtiPositions));

        //Komarovo
        autoptr array<ref Vector2> komaPositions = new array<ref Vector2>();
        komaPositions.Insert(new Vector2(3510.00, 2449.96));
        komaPositions.Insert(new Vector2(3486.67, 2404.27));
        komaPositions.Insert(new Vector2(3576.11, 2411.07));
        komaPositions.Insert(new Vector2(3696.17, 2401.84));
        komaPositions.Insert(new Vector2(3689.37, 2507.81));
        komaPositions.Insert(new Vector2(3471.11, 2538.92));
        komaPositions.Insert(new Vector2(3557.15, 2537.95));
        komaPositions.Insert(new Vector2(3621.80, 2486.91));
        komaPositions.Insert(new Vector2(3561.52, 2466.98));
        komaPositions.Insert(new Vector2(3619.86, 2447.53));
        komaPositions.Insert(new Vector2(3679.65, 2470.87));
        komaPositions.Insert(new Vector2(3641.73, 2426.63));
        komaPositions.Insert(new Vector2(3626.18, 2471.35));
        locations.Insert(new DmLocation("Komarovo", komaPositions));

        //Mogilevka
        autoptr array<ref Vector2> mogiPositions = new array<ref Vector2>();
        mogiPositions.Insert(new Vector2(7719.60, 5235.37));
        mogiPositions.Insert(new Vector2(7719.60, 5235.37));
        mogiPositions.Insert(new Vector2(7598.56, 5250.44));
        mogiPositions.Insert(new Vector2(7540.72, 5306.83));
        mogiPositions.Insert(new Vector2(7536.34, 5214.95));
        mogiPositions.Insert(new Vector2(7508.15, 5248.01));
        mogiPositions.Insert(new Vector2(7596.13, 5296.13));
        mogiPositions.Insert(new Vector2(7525.65, 5137.18));
        mogiPositions.Insert(new Vector2(7537.80, 5213.01));
        mogiPositions.Insert(new Vector2(7426.00, 5155.65));
        mogiPositions.Insert(new Vector2(7390.51, 5116.76));
        mogiPositions.Insert(new Vector2(7443.50, 5096.83));
        mogiPositions.Insert(new Vector2(7422.11, 5026.83));
        mogiPositions.Insert(new Vector2(7501.83, 4962.66));
        mogiPositions.Insert(new Vector2(7534.88, 4957.80));
        mogiPositions.Insert(new Vector2(7530.02, 4998.15));
        mogiPositions.Insert(new Vector2(7560.65, 5033.15));
        mogiPositions.Insert(new Vector2(7591.76, 5066.69));
        mogiPositions.Insert(new Vector2(7605.37, 5119.68));
        mogiPositions.Insert(new Vector2(7546.55, 5130.37));
        mogiPositions.Insert(new Vector2(7540.72, 5160.51));
        mogiPositions.Insert(new Vector2(7495.02, 5133.29));
        mogiPositions.Insert(new Vector2(7631.62, 5176.55));
        mogiPositions.Insert(new Vector2(7698.70, 5131.34));
        mogiPositions.Insert(new Vector2(7751.20, 5126.97));
        mogiPositions.Insert(new Vector2(7698.70, 5098.29));
        mogiPositions.Insert(new Vector2(7599.05, 5218.36));
        mogiPositions.Insert(new Vector2(7472.66, 5203.29));
        locations.Insert(new DmLocation("Mogilevka", mogiPositions));

        //Berezino military
        autoptr array<ref Vector2> berezinoPositions = new array<ref Vector2>();
        berezinoPositions.Insert(new Vector2(11702.68, 9195.70));
        berezinoPositions.Insert(new Vector2(11764.90, 9140.29));
        berezinoPositions.Insert(new Vector2(11813.51, 9084.87));
        berezinoPositions.Insert(new Vector2(11891.29, 9014.39));
        berezinoPositions.Insert(new Vector2(11927.75, 9111.61));
        berezinoPositions.Insert(new Vector2(11931.15, 9187.93));
        berezinoPositions.Insert(new Vector2(11827.12, 9201.05));
        berezinoPositions.Insert(new Vector2(12022.54, 9233.62));
        berezinoPositions.Insert(new Vector2(12086.70, 9126.19));
        berezinoPositions.Insert(new Vector2(12135.31, 9063.48));
        berezinoPositions.Insert(new Vector2(12026.91, 9072.72));
        berezinoPositions.Insert(new Vector2(12152.81, 9041.61));
        berezinoPositions.Insert(new Vector2(11957.40, 8945.36));
        berezinoPositions.Insert(new Vector2(11877.19, 9021.68));
        berezinoPositions.Insert(new Vector2(11894.69, 9030.43));
        berezinoPositions.Insert(new Vector2(11801.85, 9132.02));
        berezinoPositions.Insert(new Vector2(11729.42, 9107.72));
        berezinoPositions.Insert(new Vector2(11987.54, 9199.11));
        berezinoPositions.Insert(new Vector2(12059.96, 9198.62));
        berezinoPositions.Insert(new Vector2(12100.80, 9144.66));
        berezinoPositions.Insert(new Vector2(12150.38, 9066.89));
        berezinoPositions.Insert(new Vector2(11947.19, 9097.51));
        berezinoPositions.Insert(new Vector2(11917.05, 9129.11));
        berezinoPositions.Insert(new Vector2(12111.49, 8999.80));
        berezinoPositions.Insert(new Vector2(12028.37, 8944.87));
        berezinoPositions.Insert(new Vector2(12010.87, 8928.83));
        berezinoPositions.Insert(new Vector2(12034.69, 9143.69));
        berezinoPositions.Insert(new Vector2(12013.79, 9131.05));
        berezinoPositions.Insert(new Vector2(12044.41, 9086.33));
        berezinoPositions.Insert(new Vector2(12011.84, 9047.44));
        locations.Insert(new DmLocation("Berezino Military", berezinoPositions));

        //Lopatino
        autoptr array<ref Vector2> lopaPositions = new array<ref Vector2>();
        lopaPositions.Insert(new Vector2(2674.88, 9904.45));
        lopaPositions.Insert(new Vector2(2693.36, 9970.56));
        lopaPositions.Insert(new Vector2(2702.10, 10002.65));
        lopaPositions.Insert(new Vector2(2680.72, 10066.81));
        lopaPositions.Insert(new Vector2(2717.66, 10065.84));
        lopaPositions.Insert(new Vector2(2744.88, 10028.90));
        lopaPositions.Insert(new Vector2(2742.94, 9966.67));
        lopaPositions.Insert(new Vector2(2801.27, 9890.84));
        lopaPositions.Insert(new Vector2(2824.60, 9815.98));
        lopaPositions.Insert(new Vector2(2681.69, 9874.31));
        lopaPositions.Insert(new Vector2(2619.47, 9930.70));
        lopaPositions.Insert(new Vector2(2687.52, 10116.40));
        lopaPositions.Insert(new Vector2(2771.13, 10066.81));
        lopaPositions.Insert(new Vector2(2796.41, 10005.56));
        lopaPositions.Insert(new Vector2(2845.99, 9974.45));
        lopaPositions.Insert(new Vector2(2861.54, 9924.87));
        lopaPositions.Insert(new Vector2(2761.41, 9926.81));
        lopaPositions.Insert(new Vector2(2758.98, 9871.88));
        lopaPositions.Insert(new Vector2(2715.72, 9955.98));
        lopaPositions.Insert(new Vector2(2769.19, 9942.85));
        lopaPositions.Insert(new Vector2(2758.01, 10019.17));
        lopaPositions.Insert(new Vector2(2713.29, 10064.38));
        lopaPositions.Insert(new Vector2(2688.49, 10111.05));
        lopaPositions.Insert(new Vector2(2816.34, 9985.63));
        lopaPositions.Insert(new Vector2(2819.25, 9887.44));
        lopaPositions.Insert(new Vector2(2692.87, 9870.42));
        lopaPositions.Insert(new Vector2(2655.44, 9884.52));
        lopaPositions.Insert(new Vector2(2631.62, 9957.92));
        locations.Insert(new DmLocation("Lopatino", lopaPositions));

        //VMC
        autoptr array<ref Vector2> vmcPositions = new array<ref Vector2>();
        vmcPositions.Insert(new Vector2(4554.62, 8351.33));
        vmcPositions.Insert(new Vector2(4443.79, 8269.67));
        vmcPositions.Insert(new Vector2(4560.45, 8240.01));
        vmcPositions.Insert(new Vector2(4663.51, 8199.18));
        vmcPositions.Insert(new Vector2(4383.52, 8102.93));
        vmcPositions.Insert(new Vector2(4470.04, 8028.56));
        vmcPositions.Insert(new Vector2(4512.33, 8402.37));
        vmcPositions.Insert(new Vector2(4461.29, 8371.75));
        vmcPositions.Insert(new Vector2(4451.08, 8367.37));
        vmcPositions.Insert(new Vector2(4365.53, 8254.60));
        vmcPositions.Insert(new Vector2(4517.68, 8326.54));
        vmcPositions.Insert(new Vector2(4412.20, 8219.11));
        vmcPositions.Insert(new Vector2(4576.01, 8314.87));
        vmcPositions.Insert(new Vector2(4514.28, 8281.33));
        vmcPositions.Insert(new Vector2(4548.30, 8107.31));
        locations.Insert(new DmLocation("VMC Military", vmcPositions));

        //Vybor
        autoptr array<ref Vector2> vyborPositions = new array<ref Vector2>();
        vyborPositions.Insert(new Vector2(3761.80, 8728.07));
        vyborPositions.Insert(new Vector2(3802.63, 8813.62));
        vyborPositions.Insert(new Vector2(3824.02, 8858.34));
        vyborPositions.Insert(new Vector2(3803.60, 8872.93));
        vyborPositions.Insert(new Vector2(3815.27, 8899.18));
        vyborPositions.Insert(new Vector2(3827.91, 8927.37));
        vyborPositions.Insert(new Vector2(3786.10, 8944.87));
        vyborPositions.Insert(new Vector2(3733.60, 8966.26));
        vyborPositions.Insert(new Vector2(3678.19, 8928.34));
        vyborPositions.Insert(new Vector2(3733.60, 8899.18));
        vyborPositions.Insert(new Vector2(3799.71, 9049.87));
        vyborPositions.Insert(new Vector2(3828.88, 9058.62));
        vyborPositions.Insert(new Vector2(3830.82, 9108.20));
        vyborPositions.Insert(new Vector2(3891.10, 8959.46));
        vyborPositions.Insert(new Vector2(3878.46, 8923.48));
        vyborPositions.Insert(new Vector2(3951.37, 8940.01));
        vyborPositions.Insert(new Vector2(3876.52, 8919.59));
        vyborPositions.Insert(new Vector2(3892.07, 8848.62));
        vyborPositions.Insert(new Vector2(3892.07, 8829.18));
        vyborPositions.Insert(new Vector2(3889.15, 8825.29));
        vyborPositions.Insert(new Vector2(3952.35, 8804.87));
        vyborPositions.Insert(new Vector2(3975.68, 8930.29));
        vyborPositions.Insert(new Vector2(3925.13, 8952.65));
        vyborPositions.Insert(new Vector2(3968.87, 8870.01));
        vyborPositions.Insert(new Vector2(3963.04, 8805.84));
        vyborPositions.Insert(new Vector2(3933.88, 8982.79));
        vyborPositions.Insert(new Vector2(3743.33, 9045.98));
        vyborPositions.Insert(new Vector2(3853.18, 9131.54));
        vyborPositions.Insert(new Vector2(3618.88, 8927.37));
        vyborPositions.Insert(new Vector2(3702.49, 8872.93));
        vyborPositions.Insert(new Vector2(3801.66, 8843.76));
        vyborPositions.Insert(new Vector2(3720.96, 8831.12));
        vyborPositions.Insert(new Vector2(3831.80, 8766.96));
        vyborPositions.Insert(new Vector2(3886.24, 8822.37));
        vyborPositions.Insert(new Vector2(3932.90, 8876.82));
        vyborPositions.Insert(new Vector2(3812.35, 8982.79));
        vyborPositions.Insert(new Vector2(3824.02, 9028.48));
        vyborPositions.Insert(new Vector2(3828.88, 8892.37));
        vyborPositions.Insert(new Vector2(3737.49, 8996.40));
        vyborPositions.Insert(new Vector2(3911.51, 8836.96));
        vyborPositions.Insert(new Vector2(3911.51, 8836.96));
        vyborPositions.Insert(new Vector2(3847.35, 8815.57));
        locations.Insert(new DmLocation("Vybor", vyborPositions));

        //Vavilovo
        autoptr array<ref Vector2> vavilovoPositions = new array<ref Vector2>();
        vavilovoPositions.Insert(new Vector2(2397.81, 11200.42));
        vavilovoPositions.Insert(new Vector2(2320.03, 11233.48));
        vavilovoPositions.Insert(new Vector2(2240.31, 11195.56));
        vavilovoPositions.Insert(new Vector2(2197.54, 11136.25));
        vavilovoPositions.Insert(new Vector2(2202.40, 11083.75));
        vavilovoPositions.Insert(new Vector2(2202.40, 11004.03));
        vavilovoPositions.Insert(new Vector2(2167.40, 10939.87));
        vavilovoPositions.Insert(new Vector2(2154.76, 10889.31));
        vavilovoPositions.Insert(new Vector2(2152.81, 10826.12));
        vavilovoPositions.Insert(new Vector2(2211.15, 10949.59));
        vavilovoPositions.Insert(new Vector2(2161.56, 10994.31));
        vavilovoPositions.Insert(new Vector2(2170.31, 11137.23));
        vavilovoPositions.Insert(new Vector2(2171.29, 11202.36));
        vavilovoPositions.Insert(new Vector2(2248.09, 10989.45));
        vavilovoPositions.Insert(new Vector2(2489.19, 10972.92));
        vavilovoPositions.Insert(new Vector2(2289.89, 10968.06));
        vavilovoPositions.Insert(new Vector2(2377.39, 10997.23));
        vavilovoPositions.Insert(new Vector2(2491.14, 10992.37));
        vavilovoPositions.Insert(new Vector2(2527.11, 10992.37));
        vavilovoPositions.Insert(new Vector2(2563.08, 11003.06));
        vavilovoPositions.Insert(new Vector2(2230.59, 11051.67));
        vavilovoPositions.Insert(new Vector2(2244.20, 11133.34));
        vavilovoPositions.Insert(new Vector2(2255.87, 11148.89));
        vavilovoPositions.Insert(new Vector2(2209.20, 11217.92));
        vavilovoPositions.Insert(new Vector2(2384.20, 11179.03));
        vavilovoPositions.Insert(new Vector2(2143.09, 11142.09));
        vavilovoPositions.Insert(new Vector2(2257.81, 11024.45));
        vavilovoPositions.Insert(new Vector2(2336.56, 10948.62));
        vavilovoPositions.Insert(new Vector2(2493.08, 10970.00));
        vavilovoPositions.Insert(new Vector2(2499.89, 11012.78));
        vavilovoPositions.Insert(new Vector2(2161.56, 11082.78));
        vavilovoPositions.Insert(new Vector2(2146.01, 10959.31));
        vavilovoPositions.Insert(new Vector2(2277.26, 11063.34));
        locations.Insert(new DmLocation("Vavilovo", vavilovoPositions));

        //Krona
        autoptr array<ref Vector2> kronaPositions = new array<ref Vector2>();
        kronaPositions.Insert(new Vector2(1352.70, 9308.00));
        kronaPositions.Insert(new Vector2(1369.23, 9289.04));
        kronaPositions.Insert(new Vector2(1342.49, 9230.22));
        kronaPositions.Insert(new Vector2(1361.93, 9192.79));
        kronaPositions.Insert(new Vector2(1421.24, 9200.57));
        kronaPositions.Insert(new Vector2(1469.36, 9170.91));
        kronaPositions.Insert(new Vector2(1471.79, 9203.48));
        kronaPositions.Insert(new Vector2(1413.46, 9257.44));
        kronaPositions.Insert(new Vector2(1414.43, 9302.65));
        kronaPositions.Insert(new Vector2(1517.49, 9170.43));
        kronaPositions.Insert(new Vector2(1443.60, 9283.20));
        kronaPositions.Insert(new Vector2(1429.99, 9304.11));
        locations.Insert(new DmLocation("Krona Castle", kronaPositions));

        //Cherno
        autoptr array<ref Vector2> chernoPositions = new array<ref Vector2>();
        chernoPositions.Insert(new Vector2(6586.02, 2618.16));
        chernoPositions.Insert(new Vector2(6550.54, 2580.24));
        chernoPositions.Insert(new Vector2(6510.68, 2528.71));
        chernoPositions.Insert(new Vector2(6547.62, 2488.85));
        chernoPositions.Insert(new Vector2(6578.24, 2524.82));
        chernoPositions.Insert(new Vector2(6606.92, 2553.50));
        chernoPositions.Insert(new Vector2(6619.56, 2556.42));
        chernoPositions.Insert(new Vector2(6595.74, 2580.73));
        chernoPositions.Insert(new Vector2(6624.42, 2553.02));
        chernoPositions.Insert(new Vector2(6594.77, 2504.41));
        chernoPositions.Insert(new Vector2(6620.54, 2518.02));
        chernoPositions.Insert(new Vector2(6658.94, 2516.56));
        chernoPositions.Insert(new Vector2(6685.67, 2512.67));
        chernoPositions.Insert(new Vector2(6662.83, 2581.21));
        chernoPositions.Insert(new Vector2(6627.34, 2563.71));
        chernoPositions.Insert(new Vector2(6625.40, 2551.07));
        chernoPositions.Insert(new Vector2(6535.47, 2590.45));
        chernoPositions.Insert(new Vector2(6582.62, 2635.66));
        chernoPositions.Insert(new Vector2(6636.58, 2669.69));
        chernoPositions.Insert(new Vector2(6626.85, 2607.46));
        chernoPositions.Insert(new Vector2(6610.33, 2620.10));
        chernoPositions.Insert(new Vector2(6663.31, 2615.24));
        chernoPositions.Insert(new Vector2(6667.69, 2599.20));
        chernoPositions.Insert(new Vector2(6670.60, 2588.02));
        chernoPositions.Insert(new Vector2(6656.51, 2579.75));
        chernoPositions.Insert(new Vector2(6665.74, 2477.67));
        chernoPositions.Insert(new Vector2(6634.63, 2490.80));
        chernoPositions.Insert(new Vector2(6612.76, 2469.89));
        chernoPositions.Insert(new Vector2(6592.34, 2665.31));
        chernoPositions.Insert(new Vector2(6547.62, 2531.14));
        chernoPositions.Insert(new Vector2(6547.62, 2531.14));
        chernoPositions.Insert(new Vector2(6575.81, 2559.82));
        chernoPositions.Insert(new Vector2(6588.45, 2547.67));
        chernoPositions.Insert(new Vector2(6621.02, 2459.69));
        chernoPositions.Insert(new Vector2(6652.13, 2667.74));
        locations.Insert(new DmLocation("Chernogorsk Police Station", chernoPositions));

        //Solnechny
        autoptr array<ref Vector2> solnePositions = new array<ref Vector2>();
        solnePositions.Insert(new Vector2(13452.63, 5984.47));
        solnePositions.Insert(new Vector2(13467.22, 6071.97));
        solnePositions.Insert(new Vector2(13475.97, 6183.77));
        solnePositions.Insert(new Vector2(13487.63, 6313.08));
        solnePositions.Insert(new Vector2(13495.41, 6402.52));
        solnePositions.Insert(new Vector2(13552.77, 6367.52));
        solnePositions.Insert(new Vector2(13589.71, 6346.13));
        solnePositions.Insert(new Vector2(13507.08, 6335.44));
        solnePositions.Insert(new Vector2(13321.39, 6128.35));
        solnePositions.Insert(new Vector2(13320.41, 6207.10));
        solnePositions.Insert(new Vector2(13335.00, 6253.77));
        solnePositions.Insert(new Vector2(13385.55, 6290.71));
        solnePositions.Insert(new Vector2(13404.02, 6350.02));
        solnePositions.Insert(new Vector2(13456.52, 6231.41));
        solnePositions.Insert(new Vector2(13407.91, 6130.30));
        solnePositions.Insert(new Vector2(13276.67, 6278.08));
        solnePositions.Insert(new Vector2(13278.61, 6334.46));
        solnePositions.Insert(new Vector2(13442.91, 6208.08));
        solnePositions.Insert(new Vector2(13379.72, 6339.33));
        solnePositions.Insert(new Vector2(13376.80, 6102.10));
        solnePositions.Insert(new Vector2(13395.27, 6006.83));
        solnePositions.Insert(new Vector2(13445.83, 6366.55));
        solnePositions.Insert(new Vector2(13281.53, 6320.85));
        solnePositions.Insert(new Vector2(13390.41, 6096.27));
        solnePositions.Insert(new Vector2(13300.97, 6212.94));
        solnePositions.Insert(new Vector2(13319.44, 6261.55));
        locations.Insert(new DmLocation("Solnichniy Survival", solnePositions));

        //Guglovo
        autoptr array<ref Vector2> gugPositions = new array<ref Vector2>();
        gugPositions.Insert(new Vector2(8373.40, 6694.19));
        gugPositions.Insert(new Vector2(8340.83, 6619.32));
        gugPositions.Insert(new Vector2(8385.55, 6556.13));
        gugPositions.Insert(new Vector2(8510.97, 6629.53));
        gugPositions.Insert(new Vector2(8466.73, 6720.44));
        gugPositions.Insert(new Vector2(8415.69, 6664.05));
        gugPositions.Insert(new Vector2(8405.97, 6628.56));
        gugPositions.Insert(new Vector2(8454.58, 6660.64));
        gugPositions.Insert(new Vector2(8344.72, 6654.81));
        gugPositions.Insert(new Vector2(8449.23, 6580.92));
        gugPositions.Insert(new Vector2(8531.38, 6648.98));
        gugPositions.Insert(new Vector2(8401.60, 6624.67));
        locations.Insert(new DmLocation("Guglovo", gugPositions));

        //Skalisty
        autoptr array<ref Vector2> skaliPositions = new array<ref Vector2>();
        skaliPositions.Insert(new Vector2(14137.06, 2698.37));
        skaliPositions.Insert(new Vector2(13903.73, 2783.92));
        skaliPositions.Insert(new Vector2(13670.41, 2762.53));
        skaliPositions.Insert(new Vector2(13518.74, 2818.92));
        skaliPositions.Insert(new Vector2(13433.19, 2793.64));
        skaliPositions.Insert(new Vector2(13285.42, 2770.31));
        skaliPositions.Insert(new Vector2(13444.86, 2877.25));
        skaliPositions.Insert(new Vector2(13442.91, 3050.31));
        skaliPositions.Insert(new Vector2(13279.58, 3073.64));
        skaliPositions.Insert(new Vector2(13096.81, 3147.53));
        skaliPositions.Insert(new Vector2(13026.81, 3200.03));
        skaliPositions.Insert(new Vector2(13089.03, 3299.20));
        skaliPositions.Insert(new Vector2(13232.92, 3326.42));
        skaliPositions.Insert(new Vector2(13374.86, 3404.20));
        skaliPositions.Insert(new Vector2(13423.47, 3515.03));
        skaliPositions.Insert(new Vector2(13575.13, 3413.92));
        skaliPositions.Insert(new Vector2(13695.68, 3279.75));
        skaliPositions.Insert(new Vector2(13796.79, 3040.59));
        skaliPositions.Insert(new Vector2(13944.56, 3079.48));
        skaliPositions.Insert(new Vector2(14072.89, 2943.36));
        skaliPositions.Insert(new Vector2(14035.95, 2828.64));
        skaliPositions.Insert(new Vector2(13822.07, 2900.59));
        skaliPositions.Insert(new Vector2(13664.57, 2990.03));
        skaliPositions.Insert(new Vector2(13615.96, 3141.70));
        skaliPositions.Insert(new Vector2(13328.19, 3163.09));
        skaliPositions.Insert(new Vector2(13458.47, 3433.36));
        skaliPositions.Insert(new Vector2(13234.86, 3268.09));
        skaliPositions.Insert(new Vector2(13219.31, 3172.81));
        skaliPositions.Insert(new Vector2(13460.41, 3100.86));
        skaliPositions.Insert(new Vector2(13925.12, 3015.31));
        skaliPositions.Insert(new Vector2(13615.96, 3046.42));
        locations.Insert(new DmLocation("Skalisty Utoya Island V2", solnePositions));

        return locations;
    }
}