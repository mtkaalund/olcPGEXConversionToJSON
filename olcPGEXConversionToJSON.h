#ifndef OLCPGEXCONVERSIONTOJSON_H_
#define OLCPGEXCONVERSIONTOJSON_H_

/*
    olcPGEXConversionToJSON.h

    +--------------------------------------------------------------+
    |           OneLoneCoder Pixel Game Engine Extension           |
    |             Conversion to and from nlohmann::json            |
    +--------------------------------------------------------------+

    What is it?
    ~~~~~~~~~~~
    This add conversion to and from nlohmann::json, so that olc::Pixel, olc::vi2d and olc::vf2d
    can be saved in json format.

    I really wanted it to work generic with the olc::v2_generic, but I still have not figured 
    out how to do that.

    This extension uses nlohmann::json and olc::PixelGameEngine

	License (OLC-3)
	~~~~~~~~~~~~~~~

	Copyright 2018 - 2019 OneLoneCoder.com

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions
	are met:

	1. Redistributions or derivations of source code must retain the above
	copyright notice, this list of conditions and the following disclaimer.

	2. Redistributions or derivative works in binary form must reproduce
	the above copyright notice. This list of conditions and the following
	disclaimer must be reproduced in the documentation and/or other
	materials provided with the distribution.

	3. Neither the name of the copyright holder nor the names of its
	contributors may be used to endorse or promote products derived
	from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
	HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
	THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

	Links
	~~~~~
        https://github.com/OneLoneCoder/olcPixelGameEngine
        https://github.com/nlohmann/json

	Author
	~~~~~~
	Michael T. Kaalund
*/

#include <nlohmann/json.hpp>
#include <olcPixelGameEngine.h>

namespace olc
{
    // olc::vi2d to and from json
    void to_json(nlohmann::json &j, const olc::vi2d& v) {
        j = nlohmann::json{{"x", v.x, "y", v.y}};
    }

    void from_json(const nlohmann::json &j, olc::vi2d& v ) {
        j.at("x").get_to(v.x);
        j.at("y").get_to(v.y);
    }
    // olc::vf2d to and from json
    void to_json(nlohmann::json &j, const olc::vf2d& v) {
        j = nlohmann::json{{"x", v.x, "y", v.y}};
    }

    void from_json(const nlohmann::json &j, olc::vf2d& v ) {
        j.at("x").get_to(v.x);
        j.at("y").get_to(v.y);
    }
    // olc::Pixel to and from json
    void to_json(nlohmann::json &j, const olc::Pixel& v ) {
        j = nlohmann::json{
            {
                "r", v.r,
                "g", v.g,
                "b", v.b,
                "a", v.a
            }
        };
    }
    void from_json(const nlohmann::json &j, olc::Pixel& v ) {
        j.at("r").get_to(v.r);
        j.at("g").get_to(v.g);
        j.at("b").get_to(v.b);
        j.at("a").get_to(v.a);
    }
}

#endif