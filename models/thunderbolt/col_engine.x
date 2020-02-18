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

 Frame Frame1_col_engine_Layer1 {

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Mesh_col_engine {
   76;
   0.000000;0.800000;-1.200000;,
   0.000000;0.800000;-1.200000;,
   0.000000;0.800000;-1.200000;,
   0.699519;0.300000;-1.200000;,
   0.699519;0.300000;-1.200000;,
   0.699519;0.300000;-1.200000;,
   0.599519;-0.700000;-1.200000;,
   0.599519;-0.700000;-1.200000;,
   0.599519;-0.700000;-1.200000;,
   0.599519;-0.700000;-1.200000;,
   0.000000;-1.250000;-1.200000;,
   0.000000;-1.250000;-1.200000;,
   0.000000;-1.250000;-1.200000;,
   -0.599519;-0.700000;-1.200000;,
   -0.599519;-0.700000;-1.200000;,
   -0.599519;-0.700000;-1.200000;,
   -0.599519;-0.700000;-1.200000;,
   -0.699519;0.300000;-1.200000;,
   -0.699519;0.300000;-1.200000;,
   -0.699519;0.300000;-1.200000;,
   0.000000;0.800000;0.100000;,
   0.000000;0.800000;0.100000;,
   0.000000;0.800000;0.100000;,
   0.000000;0.800000;0.100000;,
   0.000000;0.800000;0.100000;,
   0.000000;0.800000;0.100000;,
   0.699519;0.300000;0.100000;,
   0.699519;0.300000;0.100000;,
   0.699519;0.300000;0.100000;,
   0.699519;0.300000;0.100000;,
   0.599519;-0.700000;0.100000;,
   0.599519;-0.700000;0.100000;,
   0.599519;-0.700000;0.100000;,
   0.599519;-0.700000;0.100000;,
   0.599519;-0.700000;0.100000;,
   0.000000;-1.150000;0.100000;,
   0.000000;-1.150000;0.100000;,
   0.000000;-1.150000;0.100000;,
   0.000000;-1.150000;0.100000;,
   0.000000;-1.150000;0.100000;,
   0.000000;-1.150000;0.100000;,
   0.000000;-1.150000;0.100000;,
   0.000000;-1.150000;0.100000;,
   -0.599519;-0.700000;0.100000;,
   -0.599519;-0.700000;0.100000;,
   -0.599519;-0.700000;0.100000;,
   -0.599519;-0.700000;0.100000;,
   -0.599519;-0.700000;0.100000;,
   -0.699519;0.300000;0.100000;,
   -0.699519;0.300000;0.100000;,
   -0.699519;0.300000;0.100000;,
   -0.699519;0.300000;0.100000;,
   0.000000;0.600000;1.400000;,
   0.000000;0.600000;1.400000;,
   0.000000;0.600000;1.400000;,
   0.549519;0.200000;1.400000;,
   0.549519;0.200000;1.400000;,
   0.549519;0.200000;1.400000;,
   0.549519;0.200000;1.400000;,
   0.549519;0.200000;1.400000;,
   0.349519;-0.650000;1.400000;,
   0.349519;-0.650000;1.400000;,
   0.349519;-0.650000;1.400000;,
   0.349519;-0.650000;1.400000;,
   0.000000;-0.850000;1.400000;,
   0.000000;-0.850000;1.400000;,
   0.000000;-0.850000;1.400000;,
   -0.349519;-0.650000;1.400000;,
   -0.349519;-0.650000;1.400000;,
   -0.349519;-0.650000;1.400000;,
   -0.349519;-0.650000;1.400000;,
   -0.549519;0.200000;1.400000;,
   -0.549519;0.200000;1.400000;,
   -0.549519;0.200000;1.400000;,
   -0.549519;0.200000;1.400000;,
   -0.549519;0.200000;1.400000;;
   32;
   3;55,26,20;,
   3;6,13,3;,
   3;17,0,3;,
   3;13,17,3;,
   3;4,1,27;,
   3;27,1,21;,
   3;7,5,30;,
   3;30,5,28;,
   3;10,8,35;,
   3;36,9,31;,
   3;11,37,14;,
   3;38,43,15;,
   3;16,44,18;,
   3;44,48,18;,
   3;19,49,2;,
   3;49,22,2;,
   3;12,13,6;,
   3;56,23,52;,
   3;32,29,57;,
   3;33,58,60;,
   3;39,34,61;,
   3;40,62,64;,
   3;41,65,67;,
   3;42,68,45;,
   3;46,69,71;,
   3;47,72,50;,
   3;73,24,51;,
   3;74,53,25;,
   3;59,54,75;,
   3;63,59,75;,
   3;63,75,70;,
   3;66,63,70;;

   MeshNormals {
    76;
    0.000000;0.000000;-1.000000;,
    0.581503;0.813544;0.000000;,
    -0.581503;0.813544;0.000000;,
    0.000000;0.000000;-1.000000;,
    0.581503;0.813544;0.000000;,
    0.995037;-0.099504;0.000000;,
    0.000000;0.000000;-1.000000;,
    0.995037;-0.099504;0.000000;,
    0.674936;-0.735703;0.056593;,
    0.600308;-0.799769;0.000000;,
    0.674936;-0.735703;0.056593;,
    -0.674936;-0.735703;0.056593;,
    0.000000;0.000000;-1.000000;,
    0.000000;0.000000;-1.000000;,
    -0.674936;-0.735703;0.056593;,
    -0.600308;-0.799769;0.000000;,
    -0.995037;-0.099504;0.000000;,
    0.000000;0.000000;-1.000000;,
    -0.995037;-0.099504;0.000000;,
    -0.581503;0.813544;0.000000;,
    0.576674;0.806789;0.128600;,
    0.581503;0.813544;0.000000;,
    -0.581503;0.813544;0.000000;,
    0.584008;0.802309;0.123432;,
    -0.576674;0.806789;0.128600;,
    -0.584008;0.802309;0.123432;,
    0.576674;0.806789;0.128600;,
    0.581503;0.813544;0.000000;,
    0.995037;-0.099504;0.000000;,
    0.989373;-0.098937;0.106548;,
    0.995037;-0.099504;0.000000;,
    0.600308;-0.799769;0.000000;,
    0.989373;-0.098937;0.106548;,
    0.955241;-0.224763;0.192345;,
    0.593993;-0.791356;0.144666;,
    0.674936;-0.735703;0.056593;,
    0.600308;-0.799769;0.000000;,
    -0.674936;-0.735703;0.056593;,
    -0.600308;-0.799769;0.000000;,
    0.593993;-0.791356;0.144666;,
    0.486981;-0.851046;0.196395;,
    -0.486981;-0.851046;0.196395;,
    -0.593993;-0.791356;0.144666;,
    -0.600308;-0.799769;0.000000;,
    -0.995037;-0.099504;0.000000;,
    -0.593993;-0.791356;0.144666;,
    -0.955241;-0.224763;0.192345;,
    -0.989373;-0.098937;0.106548;,
    -0.995037;-0.099504;0.000000;,
    -0.581503;0.813544;0.000000;,
    -0.989373;-0.098937;0.106548;,
    -0.576674;0.806789;0.128600;,
    0.584008;0.802309;0.123432;,
    -0.584008;0.802309;0.123432;,
    0.000000;0.000000;1.000000;,
    0.576674;0.806789;0.128600;,
    0.584008;0.802309;0.123432;,
    0.989373;-0.098937;0.106548;,
    0.955241;-0.224763;0.192345;,
    0.000000;0.000000;1.000000;,
    0.955241;-0.224763;0.192345;,
    0.593993;-0.791356;0.144666;,
    0.486981;-0.851046;0.196395;,
    0.000000;0.000000;1.000000;,
    0.486981;-0.851046;0.196395;,
    -0.486981;-0.851046;0.196395;,
    0.000000;0.000000;1.000000;,
    -0.486981;-0.851046;0.196395;,
    -0.593993;-0.791356;0.144666;,
    -0.955241;-0.224763;0.192345;,
    0.000000;0.000000;1.000000;,
    -0.955241;-0.224763;0.192345;,
    -0.989373;-0.098937;0.106548;,
    -0.576674;0.806789;0.128600;,
    -0.584008;0.802309;0.123432;,
    0.000000;0.000000;1.000000;;
    32;
    3;55,26,20;,
    3;6,13,3;,
    3;17,0,3;,
    3;13,17,3;,
    3;4,1,27;,
    3;27,1,21;,
    3;7,5,30;,
    3;30,5,28;,
    3;10,8,35;,
    3;36,9,31;,
    3;11,37,14;,
    3;38,43,15;,
    3;16,44,18;,
    3;44,48,18;,
    3;19,49,2;,
    3;49,22,2;,
    3;12,13,6;,
    3;56,23,52;,
    3;32,29,57;,
    3;33,58,60;,
    3;39,34,61;,
    3;40,62,64;,
    3;41,65,67;,
    3;42,68,45;,
    3;46,69,71;,
    3;47,72,50;,
    3;73,24,51;,
    3;74,53,25;,
    3;59,54,75;,
    3;63,59,75;,
    3;63,75,70;,
    3;66,63,70;;
   }

   VertexDuplicationIndices {
    76;
    72;
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
    10,
    10,
    10,
    13,
    13,
    13,
    13,
    17,
    17,
    17,
    20,
    20,
    20,
    20,
    20,
    20,
    26,
    26,
    26,
    26,
    30,
    30,
    30,
    30,
    30,
    35,
    35,
    35,
    35,
    35,
    35,
    35,
    35,
    43,
    43,
    43,
    43,
    43,
    48,
    48,
    48,
    48,
    52,
    52,
    52,
    55,
    55,
    55,
    55,
    55,
    60,
    60,
    60,
    60,
    64,
    64,
    64,
    67,
    67,
    67,
    67,
    71,
    71,
    71,
    71,
    71;
   }

   MeshMaterialList {
    1;
    32;
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
