#pragma once
#include "DXGIManager.h"


///
/// SwapChain�R����RTV
///
class D3DSwapChainRTVResource: public IRenderResource
{
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_pRTV;

public:
    /// ��������
    void Create(DXGIManager *pDxgi)override;

    /// �������
    void Release()override;

    /// �����_�[�^�[�Q�b�g���N���A����
    void Clear(ID3D11DeviceContext *pDeviceContext, const float clearColor[4]);
};

