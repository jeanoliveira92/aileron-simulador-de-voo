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

 Frame Frame1_radar_Layer1 {

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Mesh_radar {
   72;
   -0.040000;0.370000;-0.140000;,
   -0.040000;0.370000;-0.140000;,
   -0.040000;0.370000;-0.140000;,
   0.040000;0.370000;-0.140000;,
   0.040000;0.370000;-0.140000;,
   0.040000;0.370000;-0.140000;,
   0.053333;0.400000;-0.030000;,
   0.053333;0.400000;-0.030000;,
   0.053333;0.400000;-0.030000;,
   0.053333;0.400000;-0.030000;,
   0.053333;0.400000;-0.030000;,
   -0.053333;0.400000;-0.030000;,
   -0.053333;0.400000;-0.030000;,
   -0.053333;0.400000;-0.030000;,
   -0.053333;0.400000;-0.030000;,
   -0.053333;0.400000;-0.030000;,
   0.280000;0.380000;-0.090000;,
   0.280000;0.380000;-0.090000;,
   0.280000;0.380000;-0.090000;,
   0.280000;0.270000;-0.090000;,
   0.280000;0.270000;-0.090000;,
   0.280000;0.270000;-0.090000;,
   -0.280000;0.380000;-0.090000;,
   -0.280000;0.380000;-0.090000;,
   -0.280000;0.380000;-0.090000;,
   -0.280000;0.270000;-0.090000;,
   -0.280000;0.270000;-0.090000;,
   -0.280000;0.270000;-0.090000;,
   -0.040000;0.250000;-0.140000;,
   -0.040000;0.250000;-0.140000;,
   -0.040000;0.250000;-0.140000;,
   0.040000;0.250000;-0.140000;,
   0.040000;0.250000;-0.140000;,
   0.040000;0.250000;-0.140000;,
   0.073333;0.400000;0.030000;,
   0.073333;0.400000;0.030000;,
   0.073333;0.400000;0.030000;,
   0.073333;0.400000;0.030000;,
   -0.073333;0.400000;0.030000;,
   -0.073333;0.400000;0.030000;,
   -0.073333;0.400000;0.030000;,
   -0.073333;0.400000;0.030000;,
   -0.045000;-0.000000;-0.050000;,
   -0.045000;-0.000000;-0.050000;,
   0.045000;-0.000000;-0.050000;,
   0.045000;-0.000000;-0.050000;,
   0.045000;-0.000000;0.050000;,
   0.045000;-0.000000;0.050000;,
   -0.045000;-0.000000;0.050000;,
   -0.045000;-0.000000;0.050000;,
   -0.053333;0.200000;-0.030000;,
   -0.053333;0.200000;-0.030000;,
   -0.053333;0.200000;-0.030000;,
   -0.053333;0.200000;-0.030000;,
   -0.053333;0.200000;-0.030000;,
   -0.053333;0.200000;-0.030000;,
   0.053333;0.200000;-0.030000;,
   0.053333;0.200000;-0.030000;,
   0.053333;0.200000;-0.030000;,
   0.053333;0.200000;-0.030000;,
   0.053333;0.200000;-0.030000;,
   0.053333;0.200000;-0.030000;,
   -0.073333;0.200000;0.030000;,
   -0.073333;0.200000;0.030000;,
   -0.073333;0.200000;0.030000;,
   -0.073333;0.200000;0.030000;,
   -0.073333;0.200000;0.030000;,
   0.073333;0.200000;0.030000;,
   0.073333;0.200000;0.030000;,
   0.073333;0.200000;0.030000;,
   0.073333;0.200000;0.030000;,
   0.073333;0.200000;0.030000;;
   34;
   3;44,67,46;,
   3;25,38,22;,
   3;19,6,16;,
   3;20,34,68;,
   3;23,39,11;,
   3;50,62,26;,
   3;7,35,17;,
   3;56,21,69;,
   3;28,3,31;,
   3;12,36,8;,
   3;29,13,0;,
   3;4,14,9;,
   3;32,10,57;,
   3;30,58,51;,
   3;63,37,40;,
   3;42,64,52;,
   3;45,53,59;,
   3;27,15,54;,
   3;48,70,65;,
   3;27,24,15;,
   3;25,66,38;,
   3;19,60,6;,
   3;20,18,34;,
   3;28,1,3;,
   3;12,41,36;,
   3;29,55,13;,
   3;4,2,14;,
   3;32,5,10;,
   3;30,33,58;,
   3;63,71,37;,
   3;42,49,64;,
   3;45,43,53;,
   3;44,61,67;,
   3;48,47,70;;

   MeshNormals {
    72;
    -0.992734;0.000000;-0.120331;,
    0.000000;0.000000;-1.000000;,
    0.000000;0.964764;-0.263117;,
    0.000000;0.000000;-1.000000;,
    0.000000;0.964764;-0.263117;,
    0.992734;0.000000;-0.120332;,
    -0.255893;0.000000;-0.966705;,
    0.080787;0.996368;-0.026929;,
    0.000000;1.000000;0.000000;,
    0.000000;0.964764;-0.263117;,
    0.992734;0.000000;-0.120332;,
    -0.080787;0.996368;-0.026929;,
    0.000000;1.000000;0.000000;,
    -0.992734;0.000000;-0.120331;,
    0.000000;0.964764;-0.263117;,
    0.255893;0.000000;-0.966705;,
    -0.255893;0.000000;-0.966705;,
    0.080787;0.996368;-0.026929;,
    0.502136;0.000000;0.864789;,
    -0.255893;0.000000;-0.966705;,
    0.502136;0.000000;0.864789;,
    0.271880;-0.958054;-0.090627;,
    -0.502135;0.000000;0.864789;,
    -0.080787;0.996368;-0.026929;,
    0.255893;0.000000;-0.966705;,
    -0.502135;0.000000;0.864789;,
    -0.271880;-0.958054;-0.090627;,
    0.255893;0.000000;-0.966705;,
    0.000000;0.000000;-1.000000;,
    -0.992734;0.000000;-0.120331;,
    0.000000;-0.910366;-0.413803;,
    0.000000;0.000000;-1.000000;,
    0.992734;0.000000;-0.120332;,
    0.000000;-0.910366;-0.413803;,
    0.502136;0.000000;0.864789;,
    0.080787;0.996368;-0.026929;,
    0.000000;1.000000;0.000000;,
    0.000000;0.000000;1.000000;,
    -0.502135;0.000000;0.864789;,
    -0.080787;0.996368;-0.026929;,
    0.000000;0.000000;1.000000;,
    0.000000;1.000000;0.000000;,
    -0.999133;-0.041630;0.000000;,
    0.000000;0.099504;-0.995037;,
    0.999133;-0.041631;0.000000;,
    0.000000;0.099504;-0.995037;,
    0.999133;-0.041631;0.000000;,
    0.000000;0.099504;0.995037;,
    0.000000;0.099504;0.995037;,
    -0.999133;-0.041630;0.000000;,
    -0.271880;-0.958054;-0.090627;,
    0.000000;-0.910366;-0.413803;,
    -0.999133;-0.041630;0.000000;,
    0.000000;0.099504;-0.995037;,
    0.255893;0.000000;-0.966705;,
    -0.992734;0.000000;-0.120331;,
    0.271880;-0.958054;-0.090627;,
    0.992734;0.000000;-0.120332;,
    0.000000;-0.910366;-0.413803;,
    0.000000;0.099504;-0.995037;,
    -0.255893;0.000000;-0.966705;,
    0.999133;-0.041631;0.000000;,
    -0.271880;-0.958054;-0.090627;,
    0.000000;0.000000;1.000000;,
    -0.999133;-0.041630;0.000000;,
    0.000000;0.099504;0.995037;,
    -0.502135;0.000000;0.864789;,
    0.999133;-0.041631;0.000000;,
    0.502136;0.000000;0.864789;,
    0.271880;-0.958054;-0.090627;,
    0.000000;0.099504;0.995037;,
    0.000000;0.000000;1.000000;;
    34;
    3;44,67,46;,
    3;25,38,22;,
    3;19,6,16;,
    3;20,34,68;,
    3;23,39,11;,
    3;50,62,26;,
    3;7,35,17;,
    3;56,21,69;,
    3;28,3,31;,
    3;12,36,8;,
    3;29,13,0;,
    3;4,14,9;,
    3;32,10,57;,
    3;30,58,51;,
    3;63,37,40;,
    3;42,64,52;,
    3;45,53,59;,
    3;27,15,54;,
    3;48,70,65;,
    3;27,24,15;,
    3;25,66,38;,
    3;19,60,6;,
    3;20,18,34;,
    3;28,1,3;,
    3;12,41,36;,
    3;29,55,13;,
    3;4,2,14;,
    3;32,5,10;,
    3;30,33,58;,
    3;63,71,37;,
    3;42,49,64;,
    3;45,43,53;,
    3;44,61,67;,
    3;48,47,70;;
   }

   VertexDuplicationIndices {
    72;
    68;
    0,
    0,
    0,
    3,
    3,
    3,
    6,
    6,
    6,
    6,
    6,
    11,
    11,
    11,
    11,
    11,
    16,
    16,
    16,
    19,
    19,
    19,
    22,
    22,
    22,
    25,
    25,
    25,
    28,
    28,
    28,
    31,
    31,
    31,
    34,
    34,
    34,
    34,
    38,
    38,
    38,
    38,
    42,
    42,
    44,
    44,
    46,
    46,
    48,
    48,
    50,
    50,
    50,
    50,
    50,
    50,
    56,
    56,
    56,
    56,
    56,
    56,
    62,
    62,
    62,
    62,
    62,
    67,
    67,
    67,
    67,
    67;
   }

   MeshMaterialList {
    1;
    34;
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
     0.784314;0.784314;0.784314;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
    }
   }
  }
 }
}
