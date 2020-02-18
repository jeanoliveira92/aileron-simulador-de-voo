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

 Frame Frame1_gra_lElevator {

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Mesh_gra_lElevator {
   59;
   0.550150;-0.000000;0.137402;,
   0.550150;-0.000000;0.137402;,
   0.550150;-0.000000;0.137402;,
   0.550150;-0.029870;0.062726;,
   0.550150;-0.029870;0.062726;,
   0.550150;0.029871;0.062726;,
   0.550150;0.029871;0.062726;,
   -0.626370;0.024994;-0.131143;,
   -0.626370;0.024994;-0.131143;,
   -0.626370;-0.024993;-0.131143;,
   -0.626370;-0.024993;-0.131143;,
   -0.626370;-0.024993;-0.131143;,
   -0.626370;-0.000000;0.038378;,
   -0.626370;-0.000000;0.038378;,
   -0.626370;-0.024993;-0.024106;,
   -0.626370;-0.024993;-0.024106;,
   -0.626370;0.024994;-0.024106;,
   -0.550150;0.029871;-0.131432;,
   -0.550150;0.029871;-0.131432;,
   -0.550150;0.029871;-0.131432;,
   -0.550150;0.029871;-0.131432;,
   -0.550150;0.029871;0.062726;,
   -0.550150;0.029871;0.062726;,
   -0.550150;0.029871;0.062726;,
   -0.550150;-0.000000;0.137402;,
   -0.550150;-0.000000;0.137402;,
   -0.550150;-0.000000;0.137402;,
   -0.550150;-0.029870;0.062726;,
   -0.550150;-0.029870;0.062726;,
   -0.550150;-0.029870;0.062726;,
   -0.550150;-0.029870;-0.131432;,
   -0.550150;-0.029870;-0.131432;,
   -0.550150;-0.029870;-0.131432;,
   -0.550150;-0.029870;-0.131432;,
   0.550150;-0.000000;-0.460006;,
   0.550150;-0.000000;-0.460006;,
   0.550150;-0.000000;-0.460006;,
   0.550150;-0.000000;-0.460006;,
   0.440150;-0.029870;-0.131432;,
   0.440150;-0.029870;-0.131432;,
   0.440150;-0.029870;-0.131432;,
   0.440150;-0.000000;-0.460006;,
   0.440150;-0.000000;-0.460006;,
   0.440150;-0.000000;-0.460006;,
   0.440150;0.029871;-0.131432;,
   0.440150;0.029871;-0.131432;,
   0.440150;0.029871;-0.131432;,
   0.550150;0.029871;-0.131432;,
   0.550150;0.029871;-0.131432;,
   0.550150;0.029871;-0.131432;,
   0.550150;0.029871;-0.131432;,
   0.550150;0.029871;-0.131432;,
   0.550150;0.029871;-0.131432;,
   0.550150;-0.029870;-0.131432;,
   0.550150;-0.029870;-0.131432;,
   0.550150;-0.029870;-0.131432;,
   0.550150;-0.029870;-0.131432;,
   0.550150;-0.029870;-0.131432;,
   0.550150;-0.029870;-0.131432;;
   38;
   3;30,9,7;,
   3;27,21,24;,
   3;30,7,17;,
   3;30,17,47;,
   3;30,47,53;,
   3;27,18,21;,
   3;31,18,27;,
   3;3,0,25;,
   3;32,54,28;,
   3;55,48,4;,
   3;4,48,5;,
   3;4,5,1;,
   3;28,3,25;,
   3;54,3,28;,
   3;26,2,22;,
   3;16,23,19;,
   3;33,29,14;,
   3;33,14,10;,
   3;11,16,8;,
   3;2,6,22;,
   3;12,23,16;,
   3;12,26,23;,
   3;29,13,14;,
   3;29,25,13;,
   3;20,22,6;,
   3;20,6,49;,
   3;15,12,16;,
   3;8,16,19;,
   3;11,15,16;,
   3;56,50,34;,
   3;55,35,48;,
   3;38,36,57;,
   3;38,41,36;,
   3;42,51,37;,
   3;42,44,51;,
   3;58,52,45;,
   3;39,58,45;,
   3;40,46,43;;

   MeshNormals {
    59;
    0.000000;-0.928478;0.371387;,
    1.000000;0.000000;0.000000;,
    0.000000;0.928474;0.371397;,
    0.000000;-0.967825;0.251623;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    0.000000;0.992054;0.125815;,
    -0.003794;0.000000;-0.999993;,
    -0.729334;0.684158;0.000000;,
    -0.003794;0.000000;-0.999993;,
    -0.900276;-0.435320;0.000000;,
    -0.900276;-0.435320;0.000000;,
    -0.898481;-0.000005;0.439012;,
    -0.898481;-0.000005;0.439012;,
    -0.668334;-0.738727;0.087246;,
    -0.668334;-0.738727;0.087246;,
    -0.780656;0.620648;0.073302;,
    -0.001897;0.000000;-0.999998;,
    1.000000;0.000000;0.000000;,
    -0.031945;0.999490;0.000000;,
    -0.031945;0.999490;0.000000;,
    1.000000;0.000000;0.000000;,
    -0.161402;0.956191;0.244228;,
    -0.161402;0.956191;0.244228;,
    1.000000;0.000000;0.000000;,
    -0.148162;-0.918231;0.367288;,
    -0.222893;0.905117;0.362054;,
    1.000000;0.000000;0.000000;,
    -0.161676;-0.970236;0.180284;,
    -0.161676;-0.970236;0.180284;,
    -0.001897;0.000000;-0.999998;,
    1.000000;0.000000;0.000000;,
    -0.042589;-0.999093;0.000000;,
    -0.042589;-0.999093;0.000000;,
    -1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    0.000000;-0.995893;-0.090534;,
    0.000000;0.995893;-0.090538;,
    0.000000;-0.995893;-0.090534;,
    0.000000;0.000000;1.000000;,
    -1.000000;0.000000;0.000000;,
    0.000000;-0.995893;-0.090534;,
    0.000000;0.995893;-0.090538;,
    -1.000000;0.000000;0.000000;,
    0.000000;0.995893;-0.090538;,
    0.000000;0.000000;1.000000;,
    -1.000000;0.000000;0.000000;,
    0.000000;0.674337;-0.738423;,
    1.000000;0.000000;0.000000;,
    0.000000;0.998173;-0.060414;,
    -1.000000;0.000000;0.000000;,
    0.000000;0.808063;-0.589095;,
    0.000000;0.000000;1.000000;,
    0.000000;-0.674339;-0.738422;,
    0.000000;-0.999544;-0.030206;,
    1.000000;0.000000;0.000000;,
    -1.000000;0.000000;0.000000;,
    0.000000;-0.939681;-0.342053;,
    0.000000;0.000000;1.000000;;
    38;
    3;30,9,7;,
    3;27,21,24;,
    3;30,7,17;,
    3;30,17,47;,
    3;30,47,53;,
    3;27,18,21;,
    3;31,18,27;,
    3;3,0,25;,
    3;32,54,28;,
    3;55,48,4;,
    3;4,48,5;,
    3;4,5,1;,
    3;28,3,25;,
    3;54,3,28;,
    3;26,2,22;,
    3;16,23,19;,
    3;33,29,14;,
    3;33,14,10;,
    3;11,16,8;,
    3;2,6,22;,
    3;12,23,16;,
    3;12,26,23;,
    3;29,13,14;,
    3;29,25,13;,
    3;20,22,6;,
    3;20,6,49;,
    3;15,12,16;,
    3;8,16,19;,
    3;11,15,16;,
    3;56,50,34;,
    3;55,35,48;,
    3;38,36,57;,
    3;38,41,36;,
    3;42,51,37;,
    3;42,44,51;,
    3;58,52,45;,
    3;39,58,45;,
    3;40,46,43;;
   }

   MeshTextureCoords {
    59;
    0.514000;0.681000;,
    0.230000;0.681000;,
    0.370000;0.681000;,
    0.522500;0.681000;,
    0.238500;0.681000;,
    0.094500;0.681000;,
    0.378500;0.681000;,
    0.000000;1.000000;,
    0.406784;0.547000;,
    0.000000;1.000000;,
    0.550784;0.547000;,
    0.406784;0.547000;,
    0.381243;0.547000;,
    0.525243;0.547000;,
    0.532338;0.547000;,
    0.388338;0.547000;,
    0.388338;0.547000;,
    0.000000;1.000000;,
    0.000000;1.000000;,
    0.400524;0.556000;,
    0.400600;0.556000;,
    0.000000;1.000000;,
    0.378500;0.556000;,
    0.378479;0.556000;,
    0.000000;1.000000;,
    0.514000;0.556000;,
    0.370000;0.556000;,
    0.000000;1.000000;,
    0.522500;0.556000;,
    0.522479;0.556000;,
    0.000000;1.000000;,
    0.000000;1.000000;,
    0.544600;0.556000;,
    0.544524;0.556000;,
    0.153000;0.682000;,
    0.154000;0.681000;,
    0.582000;0.681000;,
    0.438000;0.681000;,
    0.544600;0.668503;,
    0.288992;0.668503;,
    0.288992;0.668503;,
    0.582000;0.668503;,
    0.438000;0.668503;,
    0.196788;0.668503;,
    0.400600;0.668503;,
    0.144992;0.668503;,
    0.144992;0.668503;,
    0.000000;1.000000;,
    0.116600;0.681000;,
    0.400600;0.681000;,
    0.115600;0.682000;,
    0.400600;0.681000;,
    0.116600;0.681000;,
    0.000000;1.000000;,
    0.544600;0.681000;,
    0.260600;0.681000;,
    0.259600;0.682000;,
    0.544600;0.681000;,
    0.260600;0.681000;;
   }

   VertexDuplicationIndices {
    59;
    54;
    0,
    0,
    0,
    3,
    3,
    5,
    5,
    7,
    7,
    9,
    9,
    9,
    12,
    12,
    14,
    14,
    16,
    17,
    17,
    17,
    17,
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
    30,
    34,
    35,
    35,
    35,
    38,
    38,
    38,
    41,
    41,
    41,
    44,
    44,
    44,
    47,
    47,
    47,
    47,
    47,
    47,
    53,
    53,
    53,
    53,
    53,
    53;
   }

   MeshMaterialList {
    2;
    38;
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
    1,
    1;

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
   }
  }
 }
}
