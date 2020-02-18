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

 Frame Frame1_col_lWing {

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Mesh_col_lWing {
   24;
   13.430243;-2.497564;18.000000;,
   13.430243;-2.497564;18.000000;,
   13.430243;-2.497564;18.000000;,
   13.430243;-2.497564;18.000000;,
   -16.422176;1.275055;-9.000000;,
   -16.422176;1.275055;-9.000000;,
   -16.422176;1.275055;-9.000000;,
   -16.422176;1.275055;-9.000000;,
   13.639513;0.495128;18.000000;,
   13.639513;0.495128;18.000000;,
   13.639513;0.495128;18.000000;,
   -16.287409;1.476347;-9.000000;,
   -16.287409;1.476347;-9.000000;,
   -16.287409;1.476347;-9.000000;,
   -16.287409;1.476347;-9.000000;,
   -16.287409;1.476347;-9.000000;,
   13.534878;-1.001218;2.000000;,
   13.534878;-1.001218;2.000000;,
   13.534878;-1.001218;2.000000;,
   13.534878;-1.001218;2.000000;,
   13.534878;-1.001218;2.000000;,
   -16.333237;1.536653;-15.000000;,
   -16.333237;1.536653;-15.000000;,
   -16.333237;1.536653;-15.000000;;
   8;
   3;0,4,16;,
   3;1,17,8;,
   3;2,11,5;,
   3;3,9,12;,
   3;6,13,21;,
   3;18,22,14;,
   3;19,15,10;,
   3;20,7,23;;

   MeshNormals {
    24;
    -0.041327;-0.994780;-0.093304;,
    0.997564;-0.069757;-0.000000;,
    -0.588611;0.394083;0.705858;,
    -0.668289;0.046731;0.742433;,
    -0.041327;-0.994780;-0.093304;,
    -0.588611;0.394083;0.705858;,
    -0.830898;0.556297;0.011938;,
    -0.059486;-0.997243;-0.044361;,
    0.997564;-0.069757;-0.000000;,
    -0.668289;0.046731;0.742433;,
    0.116538;0.988800;-0.093236;,
    -0.588611;0.394083;0.705858;,
    -0.668289;0.046731;0.742433;,
    -0.830898;0.556297;0.011938;,
    0.079340;0.996803;0.009413;,
    0.116538;0.988800;-0.093236;,
    -0.041327;-0.994780;-0.093304;,
    0.997564;-0.069757;-0.000000;,
    0.079340;0.996803;0.009413;,
    0.116538;0.988800;-0.093236;,
    -0.059486;-0.997243;-0.044361;,
    -0.830898;0.556297;0.011938;,
    0.079340;0.996803;0.009413;,
    -0.059486;-0.997243;-0.044361;;
    8;
    3;0,4,16;,
    3;1,17,8;,
    3;2,11,5;,
    3;3,9,12;,
    3;6,13,21;,
    3;18,22,14;,
    3;19,15,10;,
    3;20,7,23;;
   }

   VertexDuplicationIndices {
    24;
    22;
    0,
    0,
    0,
    0,
    4,
    4,
    4,
    4,
    8,
    8,
    8,
    11,
    11,
    11,
    11,
    11,
    16,
    16,
    16,
    16,
    16,
    21,
    21,
    21;
   }

   MeshMaterialList {
    1;
    8;
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
