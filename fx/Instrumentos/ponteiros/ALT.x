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

 Frame Frame1_veloz {

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Mesh_veloz {
   24;
   0.008600;0.000000;0.003500;,
   0.008600;0.000000;0.003500;,
   0.008600;0.000000;0.003500;,
   0.008600;-0.100000;0.003500;,
   0.008600;-0.100000;0.003500;,
   0.008600;-0.100000;0.003500;,
   0.008600;-0.100000;-0.003500;,
   0.008600;-0.100000;-0.003500;,
   0.008600;-0.100000;-0.003500;,
   0.008600;0.000000;-0.003500;,
   0.008600;0.000000;-0.003500;,
   0.008600;0.000000;-0.003500;,
   0.006600;0.000000;0.003500;,
   0.006600;0.000000;0.003500;,
   0.006600;0.000000;0.003500;,
   0.006600;-0.100000;0.003500;,
   0.006600;-0.100000;0.003500;,
   0.006600;-0.100000;0.003500;,
   0.006600;-0.100000;-0.003500;,
   0.006600;-0.100000;-0.003500;,
   0.006600;-0.100000;-0.003500;,
   0.006600;0.000000;-0.003500;,
   0.006600;0.000000;-0.003500;,
   0.006600;0.000000;-0.003500;;
   12;
   3;0,3,6;,
   3;1,15,4;,
   3;5,18,7;,
   3;9,19,21;,
   3;2,22,12;,
   3;13,20,16;,
   3;0,6,10;,
   3;1,14,15;,
   3;5,17,18;,
   3;9,8,19;,
   3;2,11,22;,
   3;13,23,20;;

   MeshNormals {
    24;
    1.000000;0.000000;0.000000;,
    0.000000;-0.000000;1.000000;,
    0.000000;1.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    0.000000;-0.000000;1.000000;,
    0.000000;-1.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    0.000000;-1.000000;0.000000;,
    0.000000;0.000000;-1.000000;,
    0.000000;0.000000;-1.000000;,
    1.000000;0.000000;0.000000;,
    0.000000;1.000000;0.000000;,
    0.000000;1.000000;0.000000;,
    -1.000000;0.000000;0.000000;,
    0.000000;-0.000000;1.000000;,
    0.000000;-0.000000;1.000000;,
    -1.000000;0.000000;0.000000;,
    0.000000;-1.000000;0.000000;,
    0.000000;-1.000000;0.000000;,
    0.000000;0.000000;-1.000000;,
    -1.000000;0.000000;0.000000;,
    0.000000;0.000000;-1.000000;,
    0.000000;1.000000;0.000000;,
    -1.000000;0.000000;0.000000;;
    12;
    3;0,3,6;,
    3;1,15,4;,
    3;5,18,7;,
    3;9,19,21;,
    3;2,22,12;,
    3;13,20,16;,
    3;0,6,10;,
    3;1,14,15;,
    3;5,17,18;,
    3;9,8,19;,
    3;2,11,22;,
    3;13,23,20;;
   }

   MeshTextureCoords {
    24;
    0.508600;0.500000;,
    0.508600;0.500000;,
    0.508600;0.500000;,
    0.508600;0.600000;,
    0.508600;0.600000;,
    0.508600;0.600000;,
    0.508600;0.600000;,
    0.508600;0.600000;,
    0.508600;0.600000;,
    0.508600;0.500000;,
    0.508600;0.500000;,
    0.508600;0.500000;,
    0.506600;0.500000;,
    0.506600;0.500000;,
    0.506600;0.500000;,
    0.506600;0.600000;,
    0.506600;0.600000;,
    0.506600;0.600000;,
    0.506600;0.600000;,
    0.506600;0.600000;,
    0.506600;0.600000;,
    0.506600;0.500000;,
    0.506600;0.500000;,
    0.506600;0.500000;;
   }

   VertexDuplicationIndices {
    24;
    22;
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
    21;
   }

   MeshMaterialList {
    3;
    12;
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
    2;

    Material {
     0.784314;0.784314;0.784314;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
    }

    Material {
     1.000000;1.000000;1.000000;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
     TextureFilename {
      "altimeter.jpg";
     }
    }

    Material {
     1.000000;1.000000;1.000000;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
    }
   }
  }
 }
}
