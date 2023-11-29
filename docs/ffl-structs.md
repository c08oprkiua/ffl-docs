These are all the structs in FFL, along with what file they are contained in, and (sometimes) descriptions of what they and their variables are used for. 

# `FFLAdditionalInfo`

* Containing file: `include/nn/ffl/FFLAdditionalInfo.h`

| Variable Name | Grouping Type | Variable Type | Occupying Bit(s), if bitmap variable |
| ------------- | ------------- | ------------- | ------------------------------------ |
| name          | Array (10+1)  | unsigned 16   | N/A                                  |
| creatorName   | Array (10+1)  | unsigned 16   | N/A                                  |
| creatorID     | N/A           | FFLCreateID   | N/A                                  |
| facelineColor | N/A           | FFLColor      | N/A                                  |
| flags         | Union         | unsigned 32   | N/A                                  |
| gender        | `flags`       | unsigned 32   | bit 31 (1 bit)                       |
| birthMonth    | `flags`       | unsigned 32   | bits 27-30 (4 bits)                  |
| birthDay      | `flags`       | unsigned 32   | bits 22-26 (5 bits)                  |
| favoriteColor | `flags`       | unsigned 32   | bits 18-21 (4 bits)                  |
| height        | `flags`       | unsigned 32   | bits 11-17 (7 bits)                  |
| build         | `flags`       | unsigned 32   | bits 4-10 (7 bits)                   |
| ngWord        | `flags`       | unsigned 32   | bit 3 (1 bit)                        |
| fontRegion    | `flags`       | unsigned 32   | bits 1-2 (2 bits)                    |
| hairDir       | `flags`       | unsigned 32   | bit 0 (1 bit)                        |
| faceType      | N/A           | unsigned 8    | N/A                                  |
| hairType      | N/A           | unsigned 8    | N/A                                  |

# `FFLAttributeBuffer`

* Containing file: `include/nn/ffl/FFLDrawParam.h`

| Variable Name | Variable Type   |
| ------------- | --------------- |
| size          | unsigned 32     |
| stride        | unsigned 32     |
| ptr           | pointer to void |

`FFLAttributeBufferParam`

- Containing file: `include/nn/ffl/FFLDrawParam.h`
- `FFL_ATTRIBUTE_BUFFER_TYPE_MAX` = 5

| Variable Name    | Grouping Type                          | Variable Type      |
| ---------------- | -------------------------------------- | ------------------ |
| attributeBuffers | Array(`FFL_ATTRIBUTE_BUFFER_TYPE_MAX`) | FFLAttributeBuffer |

# `FFLBoundingBox`

* Containing file: `include/nn/ffl/FFLBoundingBox.h`

| Variable Name | Variable Type |
| ------------- | ------------- |
| min           | FFLVec3       |
| max           | FFLVec3       |

# `FFLCharModel`

* Containing file: `include/nn/ffl/FFLCharModel.h`

* `FFL_CHAR_MODEL_SIZE` = `0x7DC` (2012)

| Variable Name | Group Type                                                   | Variable Type |
| ------------- | ------------------------------------------------------------ | ------------- |
| data          | (Unnamed union 1); Array(`FFL_CHAR_MODEL_SIZE`)              | unsigned 8    |
| data32        | (Unnamed union 1); Array(`FFL_CHAR_MODEL_SIZE` / sizeof(u32) | unsigned 32   |

# `FFLCharModelBuffer`

* Containing file: `include/nn/ffl/FFLCharModelBuffer.h`

| Variable Name  | Variable Type  |
| -------------- | -------------- |
| pBuffer        | void (pointer) |
| bufferSize     | unsigned 32    |
| pTempBuffer    | void (pointer) |
| tempBufferSize | unsigned 32    |

# `FFLCharModelDesc`

- Containing file: `include/nn/ffl/FFLCharModelDesc.h`

| Variable Name   | Variable Type   |
| --------------- | --------------- |
| resolution      | FFLResolution   |
| expressionFlag  | unsigned 32     |
| modelFlag       | unsigned 32     |
| resourceType    | FFLResourceType |
| compressTexture | bool            |

# `FFLCharModelSource`

* Containing file: `include/nn/ffl/FFLCharModelSource.h`

| Variable Name | Variable Type         |
| ------------- | --------------------- |
| dataSource    | FFLDataSource         |
| pBuffer       | constant void pointer |
| index         | unsigned 16           |

# `FFLColor`

* Containing file: `include/nn/ffl/FFLColor.h`

| Variable Name | Variable Type |
| ------------- | ------------- |
| r             | float 32      |
| g             | float 32      |
| b             | float 32      |
| a             | float 32      |

# `FFLCreateID`

* Containing file: `include/nn/ffl/FFLCreateID.h`

* `FFL_CREATE_ID_SIZE` = 10

| Variable Name | Group Type                                                   | Variable Type |
| ------------- | ------------------------------------------------------------ | ------------- |
| data          | (Unnamed union 1); Array(`FFL_CREATE_ID_SIZE`)               | unsigned 8    |
| value16       | (Unnamed union 1); Array(`FFL_CREATE_ID_SIZE` / sizeof(u16)) | unsigned 16   |

# `FFLDrawParam`

* Containing file: `include/nn/ffl/FFLDrawParam.h`

| Variable Name        | Variable Type           |
| -------------------- | ----------------------- |
| attributeBufferParam | FFLAttributeBufferParam |
| modulateParam        | FFLModulateParam        |
| cullMode             | FFLCullMode             |
| primitiveParam       | FFLPrimitiveParam       |

# `FFLPrimitiveParam`

* Containing file: `include/nn/ffl/FFLDrawParam.h`

| Variable Name | Variable Type    |
| ------------- | ---------------- |
| primitiveType | GX2PrimitiveType |
| indexCount    | unsigned 32      |
| indexFormat   | GX2IndexFormat   |
| pIndexBuffer  | pointer to void  |

# `FFLiAuthorID`

* Containing file: `include/nn/ffl/FFLiAuthorID.h`

* `FFLI_AUTHOR_ID_SIZE` = (sizeof(u64))

| Variable Name | Group Type                                                    | Variable Type |
| ------------- | ------------------------------------------------------------- | ------------- |
| data          | (Unnamed union 1); Array(`FFLI_AUTHOR_ID_SIZE`)               | unsigned 8    |
| value16       | (Unnamed union 1); Array(`FFLI_AUTHOR_ID_SIZE` / sizeof(u16)) | unsigned 16   |


