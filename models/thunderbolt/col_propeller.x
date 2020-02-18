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

 Frame Frame1_col_propeller_Layer1 {

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Mesh_col_propeller {
   8;
   -0.200000;-0.200000;-0.360000;,
   -0.200000;0.200000;-0.360000;,
   0.200000;0.200000;-0.360000;,
   0.200000;-0.200000;-0.360000;,
   -0.200000;-0.200000;0.900000;,
   -0.200000;0.200000;0.900000;,
   0.200000;0.200000;0.900000;,
   0.200000;-0.200000;0.900000;;
   12;
   3;3,2,7;,
   3;3,1,2;,
   3;0,4,1;,
   3;4,5,1;,
   3;2,1,5;,
   3;2,5,6;,
   3;3,0,1;,
   3;7,2,6;,
   3;0,3,4;,
   3;3,7,4;,
   3;4,7,5;,
   3;7,6,5;;

   MeshMaterialList {
    1;
    12;
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
