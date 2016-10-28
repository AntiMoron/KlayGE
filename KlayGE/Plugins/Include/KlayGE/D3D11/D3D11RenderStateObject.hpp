// D3D11RenderStateObject.hpp
// KlayGE D3D11渲染状态对象类 头文件
// Ver 3.8.0
// 版权所有(C) 龚敏敏, 2009
// Homepage: http://www.klayge.org
//
// 3.8.0
// 初次建立 (2009.1.30)
//
// 修改记录
/////////////////////////////////////////////////////////////////////////////////

#ifndef _D3D11RENDERSTATEOBJECT_HPP
#define _D3D11RENDERSTATEOBJECT_HPP

#pragma once

#include <KlayGE/PreDeclare.hpp>
#include <KlayGE/RenderStateObject.hpp>

namespace KlayGE
{
	class D3D11RenderStateObject : public RenderStateObject
	{
	public:
		D3D11RenderStateObject(RasterizerStateDesc const & rs_desc, DepthStencilStateDesc const & dss_desc,
			BlendStateDesc const & bs_desc);

		void Active();

		ID3D11RasterizerState* D3DRasterizerState() const
		{
			return rasterizer_state_.get();
		}

		ID3D11DepthStencilState* D3DDepthStencilState() const
		{
			return depth_stencil_state_.get();
		}

		ID3D11BlendState* D3DBlendState() const
		{
			return blend_state_.get();
		}

	private:
		ID3D11RasterizerStatePtr rasterizer_state_;
		ID3D11DepthStencilStatePtr depth_stencil_state_;
		ID3D11BlendStatePtr blend_state_;
	};

	class D3D11SamplerStateObject : public SamplerStateObject
	{
	public:
		explicit D3D11SamplerStateObject(SamplerStateDesc const & desc);

		ID3D11SamplerState* D3DSamplerState() const
		{
			return sampler_state_.get();
		}

	private:
		ID3D11SamplerStatePtr sampler_state_;
	};
}

#endif			// _D3D11RENDERSTATEOBJECT_HPP
