//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2015, Image Engine Design Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the name of Image Engine Design nor the names of any
//       other contributors to this software may be used to endorse or
//       promote products derived from this software without specific prior
//       written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////

#ifndef IECOREALEMBIC_TOALEMBICCAMERACONVERTER_H
#define IECOREALEMBIC_TOALEMBICCAMERACONVERTER_H

#include "Alembic/AbcGeom/OCamera.h"

#include "IECoreAlembic/ToAlembicConverter.h"
#include "IECoreAlembic/Export.h"

namespace IECore
{
IE_CORE_FORWARDDECLARE( Camera );
} // namespace IECore

namespace IECoreAlembic
{

class IECOREALEMBIC_API ToAlembicCameraConverter : public ToAlembicConverter
{

	public :

		typedef IECore::Camera InputType;

		IE_CORE_DECLARERUNTIMETYPEDEXTENSION( ToAlembicCameraConverter, ToAlembicCameraConverterTypeId, ToAlembicConverter );

		ToAlembicCameraConverter( Alembic::Abc::OObject transform );
		virtual ~ToAlembicCameraConverter();

	protected :

		virtual void ensureAlembicObject( Alembic::Abc::OObject &transform );
		virtual void updateTimeSampling( Alembic::Abc::TimeSamplingPtr timeSampling );
		virtual void writeAlembicObject();

	private :

		static ConverterDescription<ToAlembicCameraConverter> g_description;

		Alembic::AbcGeom::OCamera m_camera;

};

IE_CORE_DECLAREPTR( ToAlembicCameraConverter );

} // namespace IECoreAlembic

#endif // IECOREALEMBIC_TOALEMBICCAMERACONVERTER_H
