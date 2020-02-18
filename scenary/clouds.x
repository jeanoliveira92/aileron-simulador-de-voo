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

 Frame Frame1_clouds {

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Mesh_clouds {
   144;
   2550.000000;750.000000;0.000000;,
   2550.000000;750.000000;0.000000;,
   2550.000000;750.000000;0.000000;,
   2463.110840;750.000000;685.870483;,
   2463.110840;750.000000;685.870483;,
   2463.110840;750.000000;685.870483;,
   2208.364746;750.000000;1325.000000;,
   2208.364746;750.000000;1325.000000;,
   2208.364746;750.000000;1325.000000;,
   1803.122314;750.000000;1873.832886;,
   1803.122314;750.000000;1873.832886;,
   1803.122314;750.000000;1873.832886;,
   1275.000000;750.000000;2294.967285;,
   1275.000000;750.000000;2294.967285;,
   1275.000000;750.000000;2294.967285;,
   659.988586;750.000000;2559.703369;,
   659.988586;750.000000;2559.703369;,
   659.988586;750.000000;2559.703369;,
   0.000000;750.000000;2650.000000;,
   0.000000;750.000000;2650.000000;,
   0.000000;750.000000;2650.000000;,
   -659.988586;750.000000;2559.703369;,
   -659.988586;750.000000;2559.703369;,
   -659.988586;750.000000;2559.703369;,
   -1275.000000;750.000000;2294.967285;,
   -1275.000000;750.000000;2294.967285;,
   -1275.000000;750.000000;2294.967285;,
   -1803.122314;750.000000;1873.832886;,
   -1803.122314;750.000000;1873.832886;,
   -1803.122314;750.000000;1873.832886;,
   -2208.364746;750.000000;1325.000000;,
   -2208.364746;750.000000;1325.000000;,
   -2208.364746;750.000000;1325.000000;,
   -2463.110840;750.000000;685.870483;,
   -2463.110840;750.000000;685.870483;,
   -2463.110840;750.000000;685.870483;,
   -2550.000000;750.000000;0.000000;,
   -2550.000000;750.000000;0.000000;,
   -2550.000000;750.000000;0.000000;,
   -2463.110840;750.000000;-685.870483;,
   -2463.110840;750.000000;-685.870483;,
   -2463.110840;750.000000;-685.870483;,
   -2208.364746;750.000000;-1325.000000;,
   -2208.364746;750.000000;-1325.000000;,
   -2208.364746;750.000000;-1325.000000;,
   -1803.122314;750.000000;-1873.832886;,
   -1803.122314;750.000000;-1873.832886;,
   -1803.122314;750.000000;-1873.832886;,
   -1275.000000;750.000000;-2294.967285;,
   -1275.000000;750.000000;-2294.967285;,
   -1275.000000;750.000000;-2294.967285;,
   -659.988586;750.000000;-2559.703369;,
   -659.988586;750.000000;-2559.703369;,
   -659.988586;750.000000;-2559.703369;,
   0.000000;750.000000;-2650.000000;,
   0.000000;750.000000;-2650.000000;,
   0.000000;750.000000;-2650.000000;,
   659.988586;750.000000;-2559.703369;,
   659.988586;750.000000;-2559.703369;,
   659.988586;750.000000;-2559.703369;,
   1275.000000;750.000000;-2294.967285;,
   1275.000000;750.000000;-2294.967285;,
   1275.000000;750.000000;-2294.967285;,
   1803.122314;750.000000;-1873.832886;,
   1803.122314;750.000000;-1873.832886;,
   1803.122314;750.000000;-1873.832886;,
   2208.364746;750.000000;-1325.000000;,
   2208.364746;750.000000;-1325.000000;,
   2208.364746;750.000000;-1325.000000;,
   2463.110840;750.000000;-685.870483;,
   2463.110840;750.000000;-685.870483;,
   2463.110840;750.000000;-685.870483;,
   2550.000000;752.000000;0.000000;,
   2550.000000;752.000000;0.000000;,
   2550.000000;752.000000;0.000000;,
   2463.110840;752.000000;685.870483;,
   2463.110840;752.000000;685.870483;,
   2463.110840;752.000000;685.870483;,
   2208.364746;752.000000;1325.000000;,
   2208.364746;752.000000;1325.000000;,
   2208.364746;752.000000;1325.000000;,
   1803.122314;752.000000;1873.832886;,
   1803.122314;752.000000;1873.832886;,
   1803.122314;752.000000;1873.832886;,
   1275.000000;752.000000;2294.967285;,
   1275.000000;752.000000;2294.967285;,
   1275.000000;752.000000;2294.967285;,
   659.988586;752.000000;2559.703369;,
   659.988586;752.000000;2559.703369;,
   659.988586;752.000000;2559.703369;,
   0.000000;752.000000;2650.000000;,
   0.000000;752.000000;2650.000000;,
   0.000000;752.000000;2650.000000;,
   -659.988586;752.000000;2559.703369;,
   -659.988586;752.000000;2559.703369;,
   -659.988586;752.000000;2559.703369;,
   -1275.000000;752.000000;2294.967285;,
   -1275.000000;752.000000;2294.967285;,
   -1275.000000;752.000000;2294.967285;,
   -1803.122314;752.000000;1873.832886;,
   -1803.122314;752.000000;1873.832886;,
   -1803.122314;752.000000;1873.832886;,
   -2208.364746;752.000000;1325.000000;,
   -2208.364746;752.000000;1325.000000;,
   -2208.364746;752.000000;1325.000000;,
   -2463.110840;752.000000;685.870483;,
   -2463.110840;752.000000;685.870483;,
   -2463.110840;752.000000;685.870483;,
   -2550.000000;752.000000;0.000000;,
   -2550.000000;752.000000;0.000000;,
   -2550.000000;752.000000;0.000000;,
   -2463.110840;752.000000;-685.870483;,
   -2463.110840;752.000000;-685.870483;,
   -2463.110840;752.000000;-685.870483;,
   -2208.364746;752.000000;-1325.000000;,
   -2208.364746;752.000000;-1325.000000;,
   -2208.364746;752.000000;-1325.000000;,
   -1803.122314;752.000000;-1873.832886;,
   -1803.122314;752.000000;-1873.832886;,
   -1803.122314;752.000000;-1873.832886;,
   -1275.000000;752.000000;-2294.967285;,
   -1275.000000;752.000000;-2294.967285;,
   -1275.000000;752.000000;-2294.967285;,
   -659.988586;752.000000;-2559.703369;,
   -659.988586;752.000000;-2559.703369;,
   -659.988586;752.000000;-2559.703369;,
   0.000000;752.000000;-2650.000000;,
   0.000000;752.000000;-2650.000000;,
   0.000000;752.000000;-2650.000000;,
   659.988586;752.000000;-2559.703369;,
   659.988586;752.000000;-2559.703369;,
   659.988586;752.000000;-2559.703369;,
   1275.000000;752.000000;-2294.967285;,
   1275.000000;752.000000;-2294.967285;,
   1275.000000;752.000000;-2294.967285;,
   1803.122314;752.000000;-1873.832886;,
   1803.122314;752.000000;-1873.832886;,
   1803.122314;752.000000;-1873.832886;,
   2208.364746;752.000000;-1325.000000;,
   2208.364746;752.000000;-1325.000000;,
   2208.364746;752.000000;-1325.000000;,
   2463.110840;752.000000;-685.870483;,
   2463.110840;752.000000;-685.870483;,
   2463.110840;752.000000;-685.870483;;
   92;
   3;0,63,66;,
   3;1,75,3;,
   3;4,78,6;,
   3;7,81,9;,
   3;10,84,12;,
   3;13,87,15;,
   3;16,90,18;,
   3;21,91,93;,
   3;24,94,96;,
   3;27,97,99;,
   3;30,100,102;,
   3;33,103,105;,
   3;36,106,108;,
   3;39,109,111;,
   3;42,112,114;,
   3;45,115,117;,
   3;48,118,120;,
   3;51,121,123;,
   3;54,124,126;,
   3;55,129,57;,
   3;58,132,60;,
   3;61,135,64;,
   3;65,138,67;,
   3;68,141,69;,
   3;70,72,2;,
   3;73,139,142;,
   3;0,5,8;,
   3;0,8,11;,
   3;0,11,14;,
   3;0,14,17;,
   3;0,17,19;,
   3;0,19,22;,
   3;0,22,25;,
   3;0,25,28;,
   3;0,28,31;,
   3;0,31,34;,
   3;0,34,37;,
   3;0,37,40;,
   3;0,40,43;,
   3;0,43,46;,
   3;0,46,49;,
   3;0,49,52;,
   3;0,52,56;,
   3;0,56,59;,
   3;0,59,62;,
   3;0,62,63;,
   3;0,66,71;,
   3;1,74,75;,
   3;4,76,78;,
   3;7,79,81;,
   3;10,82,84;,
   3;13,85,87;,
   3;16,88,90;,
   3;21,20,91;,
   3;24,23,94;,
   3;27,26,97;,
   3;30,29,100;,
   3;33,32,103;,
   3;36,35,106;,
   3;39,38,109;,
   3;42,41,112;,
   3;45,44,115;,
   3;48,47,118;,
   3;51,50,121;,
   3;54,53,124;,
   3;55,127,129;,
   3;58,130,132;,
   3;61,133,135;,
   3;65,136,138;,
   3;68,140,141;,
   3;70,143,72;,
   3;73,77,80;,
   3;73,80,83;,
   3;73,83,86;,
   3;73,86,89;,
   3;73,89,92;,
   3;73,92,95;,
   3;73,95,98;,
   3;73,98,101;,
   3;73,101,104;,
   3;73,104,107;,
   3;73,107,110;,
   3;73,110,113;,
   3;73,113,116;,
   3;73,116,119;,
   3;73,119,122;,
   3;73,122,125;,
   3;73,125,128;,
   3;73,128,131;,
   3;73,131,134;,
   3;73,134,137;,
   3;73,137,139;;

   MeshNormals {
    144;
    0.000000;-1.000000;0.000000;,
    0.992071;0.000000;0.125680;,
    0.992071;0.000000;-0.125680;,
    0.992071;0.000000;0.125680;,
    0.928930;0.000000;0.370256;,
    0.000000;-1.000000;0.000000;,
    0.928930;0.000000;0.370256;,
    0.804468;0.000000;0.593996;,
    0.000000;-1.000000;0.000000;,
    0.804468;0.000000;0.593996;,
    0.623463;0.000000;0.781852;,
    0.000000;-1.000000;0.000000;,
    0.623463;0.000000;0.781852;,
    0.395382;0.000000;0.918517;,
    0.000000;-1.000000;0.000000;,
    0.395382;0.000000;0.918517;,
    0.135553;0.000000;0.990770;,
    0.000000;-1.000000;0.000000;,
    0.135553;0.000000;0.990770;,
    0.000000;-1.000000;0.000000;,
    -0.135553;0.000000;0.990770;,
    -0.135553;0.000000;0.990770;,
    0.000000;-1.000000;0.000000;,
    -0.395382;0.000000;0.918517;,
    -0.395382;0.000000;0.918517;,
    0.000000;-1.000000;0.000000;,
    -0.623463;0.000000;0.781852;,
    -0.623463;0.000000;0.781852;,
    0.000000;-1.000000;0.000000;,
    -0.804468;0.000000;0.593996;,
    -0.804468;0.000000;0.593996;,
    0.000000;-1.000000;0.000000;,
    -0.928930;0.000000;0.370256;,
    -0.928930;0.000000;0.370256;,
    0.000000;-1.000000;0.000000;,
    -0.992071;0.000000;0.125680;,
    -0.992071;0.000000;0.125680;,
    0.000000;-1.000000;0.000000;,
    -0.992071;0.000000;-0.125680;,
    -0.992071;0.000000;-0.125680;,
    0.000000;-1.000000;0.000000;,
    -0.928930;0.000000;-0.370256;,
    -0.928930;0.000000;-0.370256;,
    0.000000;-1.000000;0.000000;,
    -0.804468;0.000000;-0.593996;,
    -0.804468;0.000000;-0.593996;,
    0.000000;-1.000000;0.000000;,
    -0.623463;0.000000;-0.781852;,
    -0.623463;0.000000;-0.781852;,
    0.000000;-1.000000;0.000000;,
    -0.395382;0.000000;-0.918517;,
    -0.395382;0.000000;-0.918517;,
    0.000000;-1.000000;0.000000;,
    -0.135553;0.000000;-0.990770;,
    -0.135553;0.000000;-0.990770;,
    0.135553;0.000000;-0.990770;,
    0.000000;-1.000000;0.000000;,
    0.135553;0.000000;-0.990770;,
    0.395382;0.000000;-0.918517;,
    0.000000;-1.000000;0.000000;,
    0.395382;0.000000;-0.918517;,
    0.623463;0.000000;-0.781852;,
    0.000000;-1.000000;0.000000;,
    0.000000;-1.000000;0.000000;,
    0.623463;0.000000;-0.781852;,
    0.804468;0.000000;-0.593996;,
    0.000000;-1.000000;0.000000;,
    0.804468;0.000000;-0.593996;,
    0.928930;0.000000;-0.370256;,
    0.928930;0.000000;-0.370256;,
    0.992071;0.000000;-0.125680;,
    0.000000;-1.000000;0.000000;,
    0.992071;0.000000;-0.125680;,
    0.000000;-1.000000;0.000000;,
    0.992071;0.000000;0.125680;,
    0.992071;0.000000;0.125680;,
    0.928930;0.000000;0.370256;,
    0.000000;-1.000000;0.000000;,
    0.928930;0.000000;0.370256;,
    0.804468;0.000000;0.593996;,
    0.000000;-1.000000;0.000000;,
    0.804468;0.000000;0.593996;,
    0.623463;0.000000;0.781852;,
    0.000000;-1.000000;0.000000;,
    0.623463;0.000000;0.781852;,
    0.395382;0.000000;0.918517;,
    0.000000;-1.000000;0.000000;,
    0.395382;0.000000;0.918517;,
    0.135553;0.000000;0.990770;,
    0.000000;-1.000000;0.000000;,
    0.135553;0.000000;0.990770;,
    -0.135553;0.000000;0.990770;,
    0.000000;-1.000000;0.000000;,
    -0.135553;0.000000;0.990770;,
    -0.395382;0.000000;0.918517;,
    0.000000;-1.000000;0.000000;,
    -0.395382;0.000000;0.918517;,
    -0.623463;0.000000;0.781852;,
    0.000000;-1.000000;0.000000;,
    -0.623463;0.000000;0.781852;,
    -0.804468;0.000000;0.593996;,
    0.000000;-1.000000;0.000000;,
    -0.804468;0.000000;0.593996;,
    -0.928930;0.000000;0.370256;,
    0.000000;-1.000000;0.000000;,
    -0.928930;0.000000;0.370256;,
    -0.992071;0.000000;0.125680;,
    0.000000;-1.000000;0.000000;,
    -0.992071;0.000000;0.125680;,
    -0.992071;0.000000;-0.125680;,
    0.000000;-1.000000;0.000000;,
    -0.992071;0.000000;-0.125680;,
    -0.928930;0.000000;-0.370256;,
    0.000000;-1.000000;0.000000;,
    -0.928930;0.000000;-0.370256;,
    -0.804468;0.000000;-0.593996;,
    0.000000;-1.000000;0.000000;,
    -0.804468;0.000000;-0.593996;,
    -0.623463;0.000000;-0.781852;,
    0.000000;-1.000000;0.000000;,
    -0.623463;0.000000;-0.781852;,
    -0.395382;0.000000;-0.918517;,
    0.000000;-1.000000;0.000000;,
    -0.395382;0.000000;-0.918517;,
    -0.135553;0.000000;-0.990770;,
    0.000000;-1.000000;0.000000;,
    -0.135553;0.000000;-0.990770;,
    0.135553;0.000000;-0.990770;,
    0.000000;-1.000000;0.000000;,
    0.135553;0.000000;-0.990770;,
    0.395382;0.000000;-0.918517;,
    0.000000;-1.000000;0.000000;,
    0.395382;0.000000;-0.918517;,
    0.623463;0.000000;-0.781852;,
    0.000000;-1.000000;0.000000;,
    0.623463;0.000000;-0.781852;,
    0.804468;0.000000;-0.593996;,
    0.000000;-1.000000;0.000000;,
    0.804468;0.000000;-0.593996;,
    0.000000;-1.000000;0.000000;,
    0.928930;0.000000;-0.370256;,
    0.928930;0.000000;-0.370256;,
    0.000000;-1.000000;0.000000;,
    0.992071;0.000000;-0.125680;;
    92;
    3;0,63,66;,
    3;1,75,3;,
    3;4,78,6;,
    3;7,81,9;,
    3;10,84,12;,
    3;13,87,15;,
    3;16,90,18;,
    3;21,91,93;,
    3;24,94,96;,
    3;27,97,99;,
    3;30,100,102;,
    3;33,103,105;,
    3;36,106,108;,
    3;39,109,111;,
    3;42,112,114;,
    3;45,115,117;,
    3;48,118,120;,
    3;51,121,123;,
    3;54,124,126;,
    3;55,129,57;,
    3;58,132,60;,
    3;61,135,64;,
    3;65,138,67;,
    3;68,141,69;,
    3;70,72,2;,
    3;73,139,142;,
    3;0,5,8;,
    3;0,8,11;,
    3;0,11,14;,
    3;0,14,17;,
    3;0,17,19;,
    3;0,19,22;,
    3;0,22,25;,
    3;0,25,28;,
    3;0,28,31;,
    3;0,31,34;,
    3;0,34,37;,
    3;0,37,40;,
    3;0,40,43;,
    3;0,43,46;,
    3;0,46,49;,
    3;0,49,52;,
    3;0,52,56;,
    3;0,56,59;,
    3;0,59,62;,
    3;0,62,63;,
    3;0,66,71;,
    3;1,74,75;,
    3;4,76,78;,
    3;7,79,81;,
    3;10,82,84;,
    3;13,85,87;,
    3;16,88,90;,
    3;21,20,91;,
    3;24,23,94;,
    3;27,26,97;,
    3;30,29,100;,
    3;33,32,103;,
    3;36,35,106;,
    3;39,38,109;,
    3;42,41,112;,
    3;45,44,115;,
    3;48,47,118;,
    3;51,50,121;,
    3;54,53,124;,
    3;55,127,129;,
    3;58,130,132;,
    3;61,133,135;,
    3;65,136,138;,
    3;68,140,141;,
    3;70,143,72;,
    3;73,77,80;,
    3;73,80,83;,
    3;73,83,86;,
    3;73,86,89;,
    3;73,89,92;,
    3;73,92,95;,
    3;73,95,98;,
    3;73,98,101;,
    3;73,101,104;,
    3;73,104,107;,
    3;73,107,110;,
    3;73,110,113;,
    3;73,113,116;,
    3;73,116,119;,
    3;73,119,122;,
    3;73,122,125;,
    3;73,125,128;,
    3;73,128,131;,
    3;73,131,134;,
    3;73,134,137;,
    3;73,137,139;;
   }

   MeshTextureCoords {
    144;
    1.000000;0.500000;,
    1.000000;0.500000;,
    1.000000;0.500000;,
    0.982963;0.370590;,
    0.982963;0.370590;,
    0.982963;0.370590;,
    0.933013;0.250000;,
    0.933013;0.250000;,
    0.933013;0.250000;,
    0.853553;0.146447;,
    0.853553;0.146447;,
    0.853553;0.146447;,
    0.750000;0.066987;,
    0.750000;0.066987;,
    0.750000;0.066987;,
    0.629410;0.017037;,
    0.629410;0.017037;,
    0.629410;0.017037;,
    0.500000;0.000000;,
    0.500000;0.000000;,
    0.500000;0.000000;,
    0.370590;0.017037;,
    0.370590;0.017037;,
    0.370590;0.017037;,
    0.250000;0.066987;,
    0.250000;0.066987;,
    0.250000;0.066987;,
    0.146447;0.146447;,
    0.146447;0.146447;,
    0.146447;0.146447;,
    0.066987;0.250000;,
    0.066987;0.250000;,
    0.066987;0.250000;,
    0.017037;0.370590;,
    0.017037;0.370590;,
    0.017037;0.370590;,
    0.000000;0.500000;,
    0.000000;0.500000;,
    0.000000;0.500000;,
    0.017037;0.629410;,
    0.017037;0.629410;,
    0.017037;0.629410;,
    0.066987;0.750000;,
    0.066987;0.750000;,
    0.066987;0.750000;,
    0.146447;0.853553;,
    0.146447;0.853553;,
    0.146447;0.853553;,
    0.250000;0.933013;,
    0.250000;0.933013;,
    0.250000;0.933013;,
    0.370590;0.982963;,
    0.370590;0.982963;,
    0.370590;0.982963;,
    0.500000;1.000000;,
    0.500000;1.000000;,
    0.500000;1.000000;,
    0.629410;0.982963;,
    0.629410;0.982963;,
    0.629410;0.982963;,
    0.750000;0.933013;,
    0.750000;0.933013;,
    0.750000;0.933013;,
    0.853553;0.853553;,
    0.853553;0.853553;,
    0.853553;0.853553;,
    0.933013;0.750000;,
    0.933013;0.750000;,
    0.933013;0.750000;,
    0.982963;0.629410;,
    0.982963;0.629410;,
    0.982963;0.629410;,
    1.000000;0.500000;,
    1.000000;0.500000;,
    1.000000;0.500000;,
    0.982963;0.370590;,
    0.982963;0.370590;,
    0.982963;0.370590;,
    0.933013;0.250000;,
    0.933013;0.250000;,
    0.933013;0.250000;,
    0.853553;0.146447;,
    0.853553;0.146447;,
    0.853553;0.146447;,
    0.750000;0.066987;,
    0.750000;0.066987;,
    0.750000;0.066987;,
    0.629410;0.017037;,
    0.629410;0.017037;,
    0.629410;0.017037;,
    0.500000;0.000000;,
    0.500000;0.000000;,
    0.500000;0.000000;,
    0.370590;0.017037;,
    0.370590;0.017037;,
    0.370590;0.017037;,
    0.250000;0.066987;,
    0.250000;0.066987;,
    0.250000;0.066987;,
    0.146447;0.146447;,
    0.146447;0.146447;,
    0.146447;0.146447;,
    0.066987;0.250000;,
    0.066987;0.250000;,
    0.066987;0.250000;,
    0.017037;0.370590;,
    0.017037;0.370590;,
    0.017037;0.370590;,
    0.000000;0.500000;,
    0.000000;0.500000;,
    0.000000;0.500000;,
    0.017037;0.629410;,
    0.017037;0.629410;,
    0.017037;0.629410;,
    0.066987;0.750000;,
    0.066987;0.750000;,
    0.066987;0.750000;,
    0.146447;0.853553;,
    0.146447;0.853553;,
    0.146447;0.853553;,
    0.250000;0.933013;,
    0.250000;0.933013;,
    0.250000;0.933013;,
    0.370590;0.982963;,
    0.370590;0.982963;,
    0.370590;0.982963;,
    0.500000;1.000000;,
    0.500000;1.000000;,
    0.500000;1.000000;,
    0.629410;0.982963;,
    0.629410;0.982963;,
    0.629410;0.982963;,
    0.750000;0.933013;,
    0.750000;0.933013;,
    0.750000;0.933013;,
    0.853553;0.853553;,
    0.853553;0.853553;,
    0.853553;0.853553;,
    0.933013;0.750000;,
    0.933013;0.750000;,
    0.933013;0.750000;,
    0.982963;0.629410;,
    0.982963;0.629410;,
    0.982963;0.629410;;
   }

   VertexDuplicationIndices {
    144;
    142;
    0,
    0,
    0,
    3,
    3,
    3,
    6,
    6,
    6,
    9,
    9,
    9,
    12,
    12,
    12,
    15,
    15,
    15,
    18,
    18,
    18,
    21,
    21,
    21,
    24,
    24,
    24,
    27,
    27,
    27,
    30,
    30,
    30,
    33,
    33,
    33,
    36,
    36,
    36,
    39,
    39,
    39,
    42,
    42,
    42,
    45,
    45,
    45,
    48,
    48,
    48,
    51,
    51,
    51,
    54,
    54,
    54,
    57,
    57,
    57,
    60,
    60,
    60,
    63,
    63,
    63,
    66,
    66,
    66,
    69,
    69,
    69,
    72,
    72,
    72,
    75,
    75,
    75,
    78,
    78,
    78,
    81,
    81,
    81,
    84,
    84,
    84,
    87,
    87,
    87,
    90,
    90,
    90,
    93,
    93,
    93,
    96,
    96,
    96,
    99,
    99,
    99,
    102,
    102,
    102,
    105,
    105,
    105,
    108,
    108,
    108,
    111,
    111,
    111,
    114,
    114,
    114,
    117,
    117,
    117,
    120,
    120,
    120,
    123,
    123,
    123,
    126,
    126,
    126,
    129,
    129,
    129,
    132,
    132,
    132,
    135,
    135,
    135,
    138,
    138,
    138,
    141,
    141,
    141;
   }

   MeshMaterialList {
    1;
    92;
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0;

    Material {
     1.000000;1.000000;1.000000;0.400000;;
     51.200001;
     0.150000;0.150000;0.150000;;
     0.000000;0.000000;0.000000;;
     TextureFilename {
      "clouds.png";
     }
    }
   }
  }
 }
}
