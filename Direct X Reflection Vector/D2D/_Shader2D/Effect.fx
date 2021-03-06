cbuffer CB_PerFrame
{
    matrix View;
    matrix Projection;
};

matrix World; //float4*4



//-----------------------------------------------------------------------------
//Stuctuers
//-----------------------------------------------------------------------------
struct VertexInput
{
    float4 Position : POSITION0;
    float2 Uv : UV0;
};

struct VertexOutput
{
    float4 Position : SV_POSITION0;
    float2 Uv : UV0;
};


//-----------------------------------------------------------------------------
//Vertex Shader
//-----------------------------------------------------------------------------
VertexOutput VS(VertexInput input)
{
    VertexOutput output;
    output.Position = mul(input.Position, World);
    output.Position = mul(output.Position, View);
    output.Position = mul(output.Position, Projection);
    output.Uv = input.Uv;

    return output;
}
//-----------------------------------------------------------------------------
//Pixel Shader
//-----------------------------------------------------------------------------
Texture2D Map;
SamplerState Sampler;

float4 PS(VertexOutput input) : SV_TARGET0
{
    //float4 color = Map.Sample(Sampler, input.Uv);
    //clip(color.a - 0.5f);

    //return color; 배경색 투명 다른방법
    return Map.Sample(Sampler, input.Uv);
}
//-----------------------------------------------------------------------------
//Blend State
//-----------------------------------------------------------------------------
BlendState AlphaBlend
{
    AlphaToCoverageEnable = false;
    BlendEnable[0] = true; //8개까지 활성화 가능
    DestBlend[0] = INV_SRC_ALPHA;
    SrcBlend[0] = SRC_ALPHA;
    BlendOp[0] = Add;

    SrcBlendAlpha[0] = One;
    DestBlendAlpha[0] = One;
    RenderTargetWriteMask[0] = 0x0F; // 0x0000ffff 동일

};


//-----------------------------------------------------------------------------
//Technique Pass
//-----------------------------------------------------------------------------
technique11 T0
{
    pass P0
    {
        SetVertexShader(CompileShader(vs_5_0, VS()));
        SetPixelShader(CompileShader(ps_5_0, PS()));

        SetBlendState(AlphaBlend, float4(0, 0, 0, 0), 0xFF);
    }   
}

