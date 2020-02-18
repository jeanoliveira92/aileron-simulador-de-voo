xof 0303txt 0032

template XSkinMeshHeader {
 <3cf169ce-ff7c-44ab-93c0-f78f62d172e2>
 WORD nMaxSkinWeightsPerVertex;
 WORD nMaxSkinWeightsPerFace;
 WORD nBones;
}

template VertexDuplicationIndices {
 <b8d65549-d7c9-4995-89cf-53a9a8b031e3>
 DWORD nIndices;
 DWORD nOriginalVertices;
 array DWORD indices[nIndices];
}

template SkinWeights {
 <6f0d123b-bad2-4167-a0d0-80224f25fabb>
 STRING transformNodeName;
 DWORD nWeights;
 array DWORD vertexIndices[nWeights];
 array FLOAT weights[nWeights];
 Matrix4x4 matrixOffset;
}


Frame Frame_SCENE_ROOT {

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Frame Frame1_gra_lWing {

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Mesh_gra_lWing {
   134;
   2.320000;-0.045735;0.415050;,
   2.320000;-0.045735;0.415050;,
   2.320000;-0.045735;0.415050;,
   1.832300;-0.045735;0.415050;,
   1.832300;-0.045735;0.415050;,
   1.832300;0.011355;0.291625;,
   2.320000;0.011355;0.291625;,
   2.320000;0.011355;0.291625;,
   1.832300;0.005753;-0.029280;,
   2.320000;0.005753;-0.029280;,
   2.320000;0.005753;-0.029280;,
   2.320000;-0.062970;-0.572351;,
   2.320000;-0.062970;-0.572351;,
   2.320000;-0.062970;-0.572351;,
   1.832300;-0.062970;-0.572351;,
   1.832300;-0.062970;-0.572351;,
   1.832300;-0.062970;-0.572351;,
   1.832300;-0.112735;-0.029280;,
   2.320000;-0.112735;-0.029280;,
   2.320000;-0.112735;-0.029280;,
   1.832300;-0.107134;0.291625;,
   2.320000;-0.107134;0.291625;,
   2.320000;-0.107134;0.291625;,
   1.832420;-0.045737;0.415050;,
   1.832420;-0.045737;0.415050;,
   -0.424403;0.078301;0.291536;,
   -0.424403;0.078301;0.291536;,
   1.834014;0.011331;0.291625;,
   -0.424778;0.064866;-0.029137;,
   -0.424778;0.064866;-0.029137;,
   1.833858;0.005731;-0.029280;,
   -0.428084;-0.053490;-0.029137;,
   -0.428084;-0.053490;-0.029137;,
   1.830550;-0.112711;-0.029280;,
   1.830706;-0.107111;0.291625;,
   -0.425911;0.024291;0.414871;,
   -0.425911;0.024291;0.414871;,
   -0.425911;0.024291;0.414871;,
   -0.425911;0.024291;0.414871;,
   -1.643482;0.008808;-0.571449;,
   -1.643482;0.008808;-0.571449;,
   -1.643482;0.008808;-0.571449;,
   -0.427709;-0.040055;0.291536;,
   -0.427709;-0.040055;0.291536;,
   -1.642039;0.060472;0.414750;,
   -1.642039;0.060472;0.414750;,
   -1.642039;0.060472;0.414750;,
   -1.642039;0.060472;0.414750;,
   -1.739719;0.064448;0.412221;,
   -1.739719;0.064448;0.412221;,
   -1.739719;0.064448;0.412221;,
   -1.739719;0.064448;0.412221;,
   -1.640567;0.113163;0.291475;,
   -1.640567;0.113163;0.291475;,
   -1.739131;0.091323;-0.034540;,
   -1.641036;0.096372;-0.029040;,
   -1.641036;0.096372;-0.029040;,
   -1.743541;0.004979;-0.571015;,
   -1.743541;0.004979;-0.571015;,
   -1.742026;-0.012317;-0.034540;,
   -1.742026;-0.012317;-0.034540;,
   -1.644341;-0.021926;-0.029040;,
   -1.644341;-0.021926;-0.029040;,
   -1.643872;-0.005135;0.291475;,
   -1.643872;-0.005135;0.291475;,
   -1.741405;0.007988;0.288673;,
   -1.741405;0.007988;0.288673;,
   -1.738510;0.111628;0.288673;,
   1.831396;-0.082417;-0.360000;,
   1.831396;-0.082417;-0.360000;,
   1.831396;-0.082417;-0.360000;,
   1.831396;-0.082417;-0.360000;,
   -0.427463;-0.031272;-0.360000;,
   -0.427463;-0.031272;-0.360000;,
   -0.427463;-0.031272;-0.360000;,
   1.832689;-0.036104;-0.360000;,
   1.832689;-0.036104;-0.360000;,
   1.832689;-0.036104;-0.360000;,
   1.832689;-0.036104;-0.360000;,
   -0.426173;0.014924;-0.360000;,
   -0.426173;0.014924;-0.360000;,
   -0.426173;0.014924;-0.360000;,
   -1.643817;-0.003173;-0.360000;,
   -1.643817;-0.003173;-0.360000;,
   -1.643817;-0.003173;-0.360000;,
   -1.643817;-0.003173;-0.360000;,
   -1.643817;-0.003173;-0.360000;,
   -1.643817;-0.003173;-0.360000;,
   -1.642529;0.042943;-0.360000;,
   -1.642529;0.042943;-0.360000;,
   -1.642529;0.042943;-0.360000;,
   -1.642529;0.042943;-0.360000;,
   -1.642529;0.042943;-0.360000;,
   -1.742945;-0.001824;-0.360000;,
   -1.742945;-0.001824;-0.360000;,
   -1.741806;0.038941;-0.360000;,
   1.811080;-0.955794;0.057734;,
   1.819963;-0.939032;0.109702;,
   1.821100;-0.939657;0.140411;,
   1.815060;-0.958273;0.152222;,
   1.820770;-0.939445;0.137700;,
   1.811088;-0.955773;0.057734;,
   1.815047;-0.958304;0.152222;,
   1.819970;-0.939022;0.109702;,
   1.811105;-0.955784;0.057734;,
   1.819980;-0.939029;0.109702;,
   1.815031;-0.958295;0.152222;,
   0.391240;-0.070174;0.109703;,
   0.430743;-0.073005;0.057734;,
   0.424559;-0.069051;0.152222;,
   0.461854;-0.070471;0.140411;,
   0.463265;-0.071373;0.140411;,
   0.464885;-0.072409;0.109703;,
   0.431251;-0.073330;0.057734;,
   0.465201;-0.072611;0.109703;,
   0.389896;-0.069314;0.140411;,
   0.391556;-0.070376;0.109703;,
   0.391306;-0.070216;0.140411;,
   0.427341;-0.070830;0.152222;,
   0.425205;-0.072219;0.057734;,
   0.386933;-0.071869;0.109703;,
   0.459619;-0.072740;0.140411;,
   0.422498;-0.071142;0.152222;,
   0.460498;-0.074053;0.109703;,
   0.386054;-0.070555;0.140411;,
   1.821071;-0.939726;0.140411;,
   1.806140;-0.975039;0.140411;,
   1.806140;-0.975039;0.140411;,
   1.805812;-0.974830;0.137700;,
   1.805812;-0.974830;0.137700;,
   1.820741;-0.939515;0.137700;,
   1.820741;-0.939515;0.137700;,
   1.805057;-0.974347;0.109702;,
   1.805057;-0.974347;0.109702;;
   94;
   3;68,75,14;,
   3;69,72,79;,
   3;69,79,76;,
   3;72,88,79;,
   3;72,82,88;,
   3;70,89,83;,
   3;70,77,89;,
   3;84,39,90;,
   3;15,9,11;,
   3;17,18,20;,
   3;20,21,3;,
   3;21,0,3;,
   3;23,27,25;,
   3;23,25,35;,
   3;30,28,25;,
   3;30,25,27;,
   3;33,34,42;,
   3;33,42,31;,
   3;34,36,42;,
   3;34,24,36;,
   3;37,26,52;,
   3;37,52,44;,
   3;29,55,52;,
   3;29,52,26;,
   3;32,43,63;,
   3;32,63,61;,
   3;43,45,63;,
   3;43,38,45;,
   3;48,53,67;,
   3;46,53,49;,
   3;54,67,56;,
   3;56,67,53;,
   3;15,8,9;,
   3;18,21,20;,
   3;64,50,65;,
   3;64,47,50;,
   3;66,51,67;,
   3;59,66,54;,
   3;66,67,54;,
   3;33,73,71;,
   3;33,31,73;,
   3;78,80,28;,
   3;78,28,30;,
   3;32,85,74;,
   3;32,61,85;,
   3;81,91,55;,
   3;81,55,29;,
   3;17,12,18;,
   3;86,93,57;,
   3;62,60,87;,
   3;60,93,86;,
   3;95,54,92;,
   3;92,54,56;,
   3;58,95,40;,
   3;40,95,92;,
   3;59,54,95;,
   3;59,95,94;,
   3;94,95,58;,
   3;8,5,6;,
   3;8,6,9;,
   3;4,1,5;,
   3;1,6,5;,
   3;17,16,12;,
   3;62,65,60;,
   3;62,64,65;,
   3;86,57,41;,
   3;22,7,2;,
   3;22,10,7;,
   3;19,10,22;,
   3;19,13,10;,
   3;123,122,121;,
   3;123,120,122;,
   3;120,124,122;,
   3;123,119,120;,
   3;128,132,130;,
   3;99,100,98;,
   3;133,107,108;,
   3;133,108,101;,
   3;102,125,110;,
   3;102,110,109;,
   3;125,112,111;,
   3;126,128,99;,
   3;128,100,99;,
   3;104,114,105;,
   3;104,113,114;,
   3;127,115,116;,
   3;129,116,133;,
   3;127,116,129;,
   3;127,118,117;,
   3;127,106,118;,
   3;132,97,130;,
   3;132,96,97;,
   3;125,131,112;,
   3;131,103,112;;

   MeshNormals {
    134;
    0.000000;-0.895335;0.445393;,
    0.000000;0.907610;0.419814;,
    1.000000;0.000000;0.000000;,
    0.000000;-0.895335;0.445393;,
    0.000000;0.907610;0.419814;,
    0.000000;0.959898;0.280349;,
    0.000000;0.991350;0.131247;,
    1.000000;0.000000;0.000000;,
    0.000000;0.998565;-0.053554;,
    0.000000;0.995975;-0.089631;,
    1.000000;0.000000;0.000000;,
    0.000000;0.992088;-0.125544;,
    0.000000;-0.995828;-0.091254;,
    1.000000;0.000000;0.000000;,
    -0.442130;0.889955;-0.111809;,
    -0.442130;0.889955;-0.111809;,
    0.000000;-0.995828;-0.091254;,
    0.000000;-0.998481;-0.055091;,
    0.000000;-0.999823;-0.018809;,
    1.000000;0.000000;0.000000;,
    0.000000;-0.986516;0.163666;,
    0.000000;-0.950902;0.309492;,
    1.000000;0.000000;0.000000;,
    0.027623;0.911414;0.410562;,
    -0.027785;-0.894908;0.445384;,
    0.028375;0.981029;0.191775;,
    0.028375;0.981029;0.191775;,
    0.028994;0.978038;0.206399;,
    0.025784;0.995287;-0.093488;,
    0.025784;0.995287;-0.093488;,
    0.027277;0.997723;-0.061691;,
    -0.026018;-0.999620;-0.009107;,
    -0.026018;-0.999620;-0.009107;,
    -0.026180;-0.999350;-0.024776;,
    -0.028581;-0.948427;0.315705;,
    0.027296;0.916733;0.398568;,
    -0.026842;-0.889091;0.456942;,
    0.027296;0.916733;0.398568;,
    -0.026842;-0.889091;0.456942;,
    0.710652;-0.702480;-0.038678;,
    -0.039104;0.986540;-0.158774;,
    0.710652;-0.702480;-0.038678;,
    -0.027808;-0.966308;0.255883;,
    -0.027808;-0.966308;0.255883;,
    0.027268;0.919066;0.393159;,
    -0.033273;-0.883357;0.467518;,
    0.027268;0.919066;0.393159;,
    -0.033273;-0.883357;0.467518;,
    -0.441757;0.833263;0.332451;,
    0.001201;0.927026;0.374994;,
    -0.515151;-0.765385;0.385751;,
    -0.629705;-0.428460;0.647992;,
    0.014098;0.978732;0.204659;,
    0.014098;0.978732;0.204659;,
    -0.712959;0.695950;-0.085692;,
    -0.004946;0.994352;-0.106014;,
    -0.004946;0.994352;-0.106014;,
    0.012170;-0.998942;-0.044345;,
    -0.711124;0.695028;-0.106016;,
    -0.741556;-0.670877;-0.004268;,
    -0.741556;-0.670877;-0.004268;,
    -0.076635;-0.997001;0.010804;,
    -0.076635;-0.997001;0.010804;,
    -0.067527;-0.964347;0.255882;,
    -0.067527;-0.964347;0.255882;,
    -0.763457;-0.634616;0.119983;,
    -0.763457;-0.634616;0.119983;,
    -0.571516;0.817894;0.066479;,
    -0.999609;0.027919;-0.001700;,
    -0.009732;-0.429821;-0.902862;,
    0.000000;0.000000;1.000000;,
    -0.009732;-0.429821;-0.902862;,
    -0.016309;-0.679816;-0.733202;,
    -0.016309;-0.679816;-0.733202;,
    -0.016309;-0.679816;-0.733202;,
    -0.999609;0.027919;-0.001700;,
    0.020499;0.840652;-0.541188;,
    0.000000;0.000000;1.000000;,
    0.020499;0.840652;-0.541188;,
    0.015512;0.650701;-0.759176;,
    0.015512;0.650701;-0.759176;,
    0.015512;0.650701;-0.759176;,
    -0.021675;-0.976959;-0.212323;,
    0.000000;0.000000;1.000000;,
    0.316624;-0.947795;-0.037868;,
    -0.021675;-0.976959;-0.212323;,
    0.139499;-0.967836;-0.209363;,
    -0.021675;-0.976959;-0.212323;,
    -0.020784;0.831374;-0.555324;,
    0.000000;0.000000;1.000000;,
    0.999610;-0.027927;0.000001;,
    -0.020784;0.831374;-0.555324;,
    -0.020784;0.831374;-0.555324;,
    -0.013601;-0.999389;-0.032183;,
    -0.999603;0.027933;0.003722;,
    -0.711437;0.694694;-0.106104;,
    0.920828;-0.388650;-0.032042;,
    0.920824;-0.388648;-0.032167;,
    0.911854;-0.385468;-0.141195;,
    0.911785;-0.385783;-0.140785;,
    0.911855;-0.385466;-0.141193;,
    -0.506334;-0.791733;-0.341737;,
    0.285553;0.446507;0.847992;,
    0.538771;0.842452;0.000001;,
    0.506335;0.791734;-0.341733;,
    0.506335;0.791734;-0.341736;,
    -0.285552;-0.446505;0.847994;,
    -0.506333;-0.791731;-0.341743;,
    -0.506334;-0.791732;-0.341740;,
    0.285553;0.446507;0.847992;,
    0.285553;0.446507;0.847992;,
    0.538771;0.842452;-0.000001;,
    0.538771;0.842452;-0.000009;,
    0.506336;0.791735;-0.341730;,
    0.506335;0.791734;-0.341733;,
    -0.538770;-0.842453;-0.000000;,
    -0.538770;-0.842453;-0.000002;,
    -0.285546;-0.446496;0.848001;,
    -0.285549;-0.446501;0.847997;,
    0.029677;0.999445;0.015129;,
    0.029673;0.999298;-0.022883;,
    0.029652;0.998683;-0.041878;,
    0.029654;0.998683;-0.041877;,
    0.029672;0.999298;-0.022883;,
    0.029656;0.998682;-0.041878;,
    0.510842;0.798781;0.317788;,
    0.911642;-0.386415;-0.139971;,
    -0.471232;-0.736846;0.484766;,
    0.915928;-0.387534;-0.104369;,
    -0.538770;-0.842453;-0.000003;,
    0.954745;0.296691;-0.020884;,
    0.954745;0.296691;-0.020884;,
    0.920758;-0.388823;-0.031955;,
    -0.524207;-0.819680;-0.230937;;
    94;
    3;68,75,14;,
    3;69,72,79;,
    3;69,79,76;,
    3;72,88,79;,
    3;72,82,88;,
    3;70,89,83;,
    3;70,77,89;,
    3;84,39,90;,
    3;15,9,11;,
    3;17,18,20;,
    3;20,21,3;,
    3;21,0,3;,
    3;23,27,25;,
    3;23,25,35;,
    3;30,28,25;,
    3;30,25,27;,
    3;33,34,42;,
    3;33,42,31;,
    3;34,36,42;,
    3;34,24,36;,
    3;37,26,52;,
    3;37,52,44;,
    3;29,55,52;,
    3;29,52,26;,
    3;32,43,63;,
    3;32,63,61;,
    3;43,45,63;,
    3;43,38,45;,
    3;48,53,67;,
    3;46,53,49;,
    3;54,67,56;,
    3;56,67,53;,
    3;15,8,9;,
    3;18,21,20;,
    3;64,50,65;,
    3;64,47,50;,
    3;66,51,67;,
    3;59,66,54;,
    3;66,67,54;,
    3;33,73,71;,
    3;33,31,73;,
    3;78,80,28;,
    3;78,28,30;,
    3;32,85,74;,
    3;32,61,85;,
    3;81,91,55;,
    3;81,55,29;,
    3;17,12,18;,
    3;86,93,57;,
    3;62,60,87;,
    3;60,93,86;,
    3;95,54,92;,
    3;92,54,56;,
    3;58,95,40;,
    3;40,95,92;,
    3;59,54,95;,
    3;59,95,94;,
    3;94,95,58;,
    3;8,5,6;,
    3;8,6,9;,
    3;4,1,5;,
    3;1,6,5;,
    3;17,16,12;,
    3;62,65,60;,
    3;62,64,65;,
    3;86,57,41;,
    3;22,7,2;,
    3;22,10,7;,
    3;19,10,22;,
    3;19,13,10;,
    3;123,122,121;,
    3;123,120,122;,
    3;120,124,122;,
    3;123,119,120;,
    3;128,132,130;,
    3;99,100,98;,
    3;133,107,108;,
    3;133,108,101;,
    3;102,125,110;,
    3;102,110,109;,
    3;125,112,111;,
    3;126,128,99;,
    3;128,100,99;,
    3;104,114,105;,
    3;104,113,114;,
    3;127,115,116;,
    3;129,116,133;,
    3;127,116,129;,
    3;127,118,117;,
    3;127,106,118;,
    3;132,97,130;,
    3;132,96,97;,
    3;125,131,112;,
    3;131,103,112;;
   }

   MeshTextureCoords {
    134;
    0.493000;0.502000;,
    0.347000;0.502000;,
    0.347000;0.502000;,
    0.493000;0.447000;,
    0.347000;0.447000;,
    0.361250;0.447000;,
    0.361250;0.502000;,
    0.361250;0.502000;,
    0.398300;0.447000;,
    0.398300;0.502000;,
    0.398300;0.502000;,
    0.461000;0.502000;,
    0.605000;0.502000;,
    0.605000;0.502000;,
    0.000000;1.000000;,
    0.461000;0.447000;,
    0.605000;0.447000;,
    0.543400;0.447000;,
    0.543400;0.502000;,
    0.543400;0.502000;,
    0.507000;0.447000;,
    0.507000;0.502000;,
    0.507000;0.502000;,
    0.347000;0.447000;,
    0.493000;0.447000;,
    0.361260;0.186000;,
    0.361250;0.186000;,
    0.361250;0.447000;,
    0.398283;0.186000;,
    0.398300;0.186000;,
    0.398300;0.447000;,
    0.543384;0.186000;,
    0.543400;0.186000;,
    0.543400;0.447000;,
    0.507000;0.447000;,
    0.347021;0.186000;,
    0.493020;0.186000;,
    0.347000;0.186000;,
    0.493000;0.186000;,
    0.000000;1.000000;,
    0.461000;0.045000;,
    0.605000;0.045000;,
    0.507010;0.186000;,
    0.507000;0.186000;,
    0.347014;0.045000;,
    0.493014;0.045000;,
    0.347000;0.045000;,
    0.493000;0.045000;,
    0.360550;0.034000;,
    0.360550;0.034000;,
    0.506313;0.034000;,
    0.360550;0.034000;,
    0.361257;0.045000;,
    0.361250;0.045000;,
    0.405494;0.034000;,
    0.398289;0.045000;,
    0.398300;0.045000;,
    0.604436;0.034000;,
    0.460425;0.034000;,
    0.405494;0.034000;,
    0.550468;0.034000;,
    0.543389;0.045000;,
    0.543400;0.045000;,
    0.507007;0.045000;,
    0.507000;0.045000;,
    0.518578;0.034000;,
    0.373035;0.034000;,
    0.373035;0.034000;,
    0.000000;1.000000;,
    0.000000;1.000000;,
    0.000000;1.000000;,
    0.580913;0.447000;,
    0.000000;1.000000;,
    0.580913;0.186000;,
    0.580957;0.186000;,
    0.000000;1.000000;,
    0.000000;1.000000;,
    0.000000;1.000000;,
    0.436483;0.447000;,
    0.000000;1.000000;,
    0.436483;0.186000;,
    0.436527;0.186000;,
    0.000000;1.000000;,
    0.000000;1.000000;,
    0.000000;1.000000;,
    0.580957;0.045000;,
    0.580986;0.045000;,
    0.580986;0.045000;,
    0.000000;1.000000;,
    0.000000;1.000000;,
    0.000000;1.000000;,
    0.436528;0.045000;,
    0.436557;0.045000;,
    0.583208;0.034000;,
    0.438819;0.034000;,
    0.438819;0.034000;,
    0.779419;0.249711;,
    0.776964;0.247957;,
    0.775513;0.248246;,
    0.774955;0.250793;,
    0.775641;0.248151;,
    0.868000;0.279523;,
    0.824000;0.279636;,
    0.843800;0.279486;,
    0.868000;0.279524;,
    0.843800;0.279486;,
    0.824000;0.279636;,
    0.843800;0.239265;,
    0.868000;0.240102;,
    0.824000;0.239925;,
    0.829500;0.240700;,
    0.829500;0.240740;,
    0.843800;0.240786;,
    0.868000;0.240117;,
    0.843800;0.240795;,
    0.829500;0.239226;,
    0.843800;0.239274;,
    0.829500;0.239267;,
    0.824000;0.240005;,
    0.533530;0.284591;,
    0.527635;0.280171;,
    0.524152;0.288567;,
    0.522812;0.284275;,
    0.527635;0.288673;,
    0.524152;0.280065;,
    0.829500;0.279518;,
    0.775513;0.252516;,
    0.829500;0.279673;,
    0.775641;0.252421;,
    0.830763;0.279663;,
    0.775641;0.248159;,
    0.830762;0.279508;,
    0.776964;0.252218;,
    0.843800;0.279642;;
   }

   VertexDuplicationIndices {
    134;
    133;
    0,
    0,
    0,
    3,
    3,
    5,
    6,
    6,
    8,
    9,
    9,
    11,
    11,
    11,
    14,
    14,
    14,
    17,
    18,
    18,
    20,
    21,
    21,
    23,
    23,
    25,
    25,
    27,
    28,
    28,
    30,
    31,
    31,
    33,
    34,
    35,
    35,
    35,
    35,
    39,
    39,
    39,
    42,
    42,
    44,
    44,
    44,
    44,
    48,
    48,
    48,
    48,
    52,
    52,
    54,
    55,
    55,
    57,
    57,
    59,
    59,
    61,
    61,
    63,
    63,
    65,
    65,
    67,
    68,
    68,
    68,
    68,
    72,
    72,
    72,
    75,
    75,
    75,
    75,
    79,
    79,
    79,
    82,
    82,
    82,
    82,
    82,
    82,
    88,
    88,
    88,
    88,
    88,
    93,
    93,
    95,
    96,
    97,
    98,
    99,
    100,
    101,
    102,
    103,
    104,
    105,
    106,
    107,
    108,
    109,
    110,
    111,
    112,
    113,
    114,
    115,
    116,
    117,
    118,
    119,
    120,
    121,
    122,
    123,
    124,
    125,
    126,
    126,
    128,
    128,
    130,
    130,
    132,
    132;
   }

   MeshMaterialList {
    4;
    94;
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3;

    Material {
     1.000000;1.000000;1.000000;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
    }

    Material {
     0.784314;0.784314;0.784314;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
    }

    Material {
     1.000000;1.000000;1.000000;1.000000;;
     34.559998;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
     TextureFilename {
      "Jabiru_160C_paint2.png";
     }
    }

    Material {
     1.000000;1.000000;1.000000;1.000000;;
     34.559998;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
     TextureFilename {
      "Jabiru_160C_paint.png";
     }
    }
   }
  }
 }
}
