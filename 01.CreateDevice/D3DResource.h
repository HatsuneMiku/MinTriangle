#pragma once
#include "DXGIManager.h"
#include "CompileShaderFromFile.h"


///
/// SwapChain�R����RTV
///
class D3DSwapChainRTVResource: public IRenderResource
{
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_pRTV;
    D3D11_TEXTURE2D_DESC m_backbufferDesc;

public:
    /// ��������
    bool Create(DXGIManager *pDxgi)override;

    /// �������
    void Release()override;

    /// �p�C�v���C���ɃZ�b�g����
    void SetupPipeline(ID3D11DeviceContext *pDeviceContext)override;

    /// �����_�[�^�[�Q�b�g���N���A����
    void Clear(ID3D11DeviceContext *pDeviceContext, const float clearColor[4]);
};


///
/// Shader
///
class D3DShader: public IRenderResource
{
    ShaderInfo m_info;

    Microsoft::WRL::ComPtr<struct ID3D11VertexShader> m_pVsh;
    Microsoft::WRL::ComPtr<struct ID3D11PixelShader> m_pPsh;
    Microsoft::WRL::ComPtr<struct ID3D11InputLayout> m_pInputLayout;

public:
    void SetInfo(const ShaderInfo &info){ m_info=info; }
    ShaderInfo GetInfo()const{ return m_info; }

    /// ��������
    bool Create(DXGIManager *pDxgi)override;

    /// �������
    void Release()override;

    /// �p�C�v���C���ɃZ�b�g����
    void SetupPipeline(ID3D11DeviceContext *pDeviceContext)override;
};


///
/// InputAssembler(���_�o�b�t�@)
///
class D3DInputAssembler: public IRenderResource
{
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_pVertexBuf;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_pIndexBuf;
    int m_indices;

public:
    /// ��������
    bool Create(DXGIManager *pDxgi)override;

    /// �������
    void Release()override;

    /// �p�C�v���C���ɃZ�b�g����
    void SetupPipeline(ID3D11DeviceContext *pDeviceContext)override;

    /// �p�C�v���C����`�悷��
    void Draw(ID3D11DeviceContext *pDeviceContext);
};

