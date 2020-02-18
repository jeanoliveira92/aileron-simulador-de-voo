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

 Frame Frame1_gra_rudder_Layer1 {

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Mesh_gra_rudder {
   37;
   0.049601;0.083671;1.109000;,
   0.041294;0.238400;1.050835;,
   0.000000;1.280000;0.340386;,
   0.000000;0.931469;0.575319;,
   0.034699;0.935372;0.253851;,
   0.034562;0.320962;0.499615;,
   0.000000;0.283671;1.009000;,
   0.000000;1.464020;-0.101418;,
   0.017814;1.292817;-0.080000;,
   0.019223;0.939426;-0.080000;,
   0.000000;1.459999;0.125625;,
   0.032425;1.286926;0.113230;,
   0.017449;0.363395;-0.080000;,
   -0.049601;0.083671;1.109000;,
   -0.041294;0.238400;1.050835;,
   0.000000;1.280000;0.340386;,
   -0.034699;0.935372;0.253851;,
   0.000000;0.931469;0.575319;,
   -0.034562;0.320962;0.499615;,
   0.000000;0.283671;1.009000;,
   -0.017814;1.292817;-0.080000;,
   -0.019223;0.939426;-0.080000;,
   0.000000;1.464020;-0.101418;,
   0.000000;1.459999;0.125625;,
   -0.032425;1.286926;0.113230;,
   -0.017449;0.363395;-0.080000;,
   -0.017722;-0.036520;-0.080000;,
   0.017722;-0.036520;-0.080000;,
   -0.017722;-0.036520;-0.080000;,
   0.017722;-0.036520;-0.080000;,
   0.000000;1.464020;-0.101418;,
   0.019223;0.939426;-0.080000;,
   -0.019223;0.939426;-0.080000;,
   -0.017814;1.292817;-0.080000;,
   0.017814;1.292817;-0.080000;,
   0.017449;0.363395;-0.080000;,
   -0.017449;0.363395;-0.080000;;
   37;
   3;31,32,34;,
   3;36,32,31;,
   3;32,33,34;,
   3;29,36,35;,
   3;29,28,36;,
   3;35,36,31;,
   3;34,33,30;,
   3;27,12,5;,
   3;5,12,4;,
   3;12,9,4;,
   3;9,8,11;,
   3;27,5,0;,
   3;4,9,11;,
   3;11,8,7;,
   3;11,7,10;,
   3;19,17,18;,
   3;18,17,16;,
   3;2,11,10;,
   3;0,5,1;,
   3;15,23,24;,
   3;24,23,22;,
   3;13,14,18;,
   3;26,13,18;,
   3;26,18,25;,
   3;18,16,25;,
   3;25,16,21;,
   3;16,24,21;,
   3;21,24,20;,
   3;24,22,20;,
   3;14,19,18;,
   3;1,5,6;,
   3;5,4,3;,
   3;3,4,2;,
   3;4,11,2;,
   3;17,15,16;,
   3;6,5,3;,
   3;16,15,24;;

   MeshNormals {
    37;
    0.999598;0.023816;-0.015396;,
    0.908255;0.415284;0.051109;,
    0.985898;0.102980;0.131906;,
    0.993932;0.054412;0.095597;,
    0.998902;0.025364;0.039381;,
    0.991688;0.125618;0.027854;,
    0.906285;0.412601;0.091698;,
    0.989642;0.139342;-0.034534;,
    0.996058;0.049180;-0.073817;,
    0.998422;-0.003740;-0.056031;,
    0.981151;0.178519;0.073987;,
    0.996255;0.084925;0.016217;,
    0.999361;-0.004928;-0.035409;,
    -0.999598;0.023816;-0.015396;,
    -0.908255;0.415284;0.051109;,
    -0.985898;0.102980;0.131906;,
    -0.998902;0.025364;0.039381;,
    -0.993932;0.054412;0.095597;,
    -0.991688;0.125618;0.027854;,
    -0.906285;0.412601;0.091698;,
    -0.996058;0.049180;-0.073817;,
    -0.998422;-0.003740;-0.056031;,
    -0.989642;0.139342;-0.034534;,
    -0.981151;0.178519;0.073987;,
    -0.996255;0.084925;0.016217;,
    -0.999361;-0.004928;-0.035409;,
    -0.999609;-0.001831;-0.027912;,
    0.999609;-0.001831;-0.027912;,
    0.000000;0.000000;-1.000000;,
    0.000000;0.000000;-1.000000;,
    0.000000;-0.124136;-0.992265;,
    0.000000;0.000000;-1.000000;,
    0.000000;0.000000;-1.000000;,
    0.000000;-0.062188;-0.998064;,
    0.000000;-0.041450;-0.999141;,
    0.000000;0.000000;-1.000000;,
    0.000000;0.000000;-1.000000;;
    37;
    3;31,32,34;,
    3;36,32,31;,
    3;32,33,34;,
    3;29,36,35;,
    3;29,28,36;,
    3;35,36,31;,
    3;34,33,30;,
    3;27,12,5;,
    3;5,12,4;,
    3;12,9,4;,
    3;9,8,11;,
    3;27,5,0;,
    3;4,9,11;,
    3;11,8,7;,
    3;11,7,10;,
    3;19,17,18;,
    3;18,17,16;,
    3;2,11,10;,
    3;0,5,1;,
    3;15,23,24;,
    3;24,23,22;,
    3;13,14,18;,
    3;26,13,18;,
    3;26,18,25;,
    3;18,16,25;,
    3;25,16,21;,
    3;16,24,21;,
    3;21,24,20;,
    3;24,22,20;,
    3;14,19,18;,
    3;1,5,6;,
    3;5,4,3;,
    3;3,4,2;,
    3;4,11,2;,
    3;17,15,16;,
    3;6,5,3;,
    3;16,15,24;;
   }

   MeshTextureCoords {
    37;
    0.516971;0.122068;,
    0.501452;0.163350;,
    0.311905;0.441249;,
    0.374585;0.348261;,
    0.288817;0.349302;,
    0.354387;0.185378;,
    0.490291;0.175428;,
    0.194031;0.490346;,
    0.199745;0.444669;,
    0.199745;0.350384;,
    0.254606;0.489273;,
    0.251299;0.443097;,
    0.199745;0.196699;,
    0.474549;0.548948;,
    0.490068;0.590230;,
    0.679616;0.868129;,
    0.702703;0.776182;,
    0.616935;0.775141;,
    0.637133;0.612258;,
    0.501229;0.602308;,
    0.791775;0.871549;,
    0.791775;0.777264;,
    0.797489;0.917226;,
    0.736914;0.916153;,
    0.740221;0.869977;,
    0.791775;0.623579;,
    0.791775;0.516881;,
    0.199745;0.090001;,
    0.128119;0.811348;,
    0.171687;0.811348;,
    0.149903;0.383020;,
    0.173532;0.532765;,
    0.126274;0.532765;,
    0.128007;0.431890;,
    0.171799;0.431890;,
    0.171351;0.697193;,
    0.128455;0.697193;;
   }

   MeshMaterialList {
    2;
    37;
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1;

    Material {
     1.000000;1.000000;1.000000;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
     TextureFilename {
      "p47-machinery.jpg";
     }
    }

    Material {
     1.000000;1.000000;1.000000;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
     TextureFilename {
      "p47-tail.jpg";
     }
    }
   }
  }
 }
}
