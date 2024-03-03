#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
namespace gm {
	namespace Textures
	{
		enum ID { Landscape, Airplane, Missile };	
	}
	class TextureHolder
	{
	public:

		void load(Textures::ID, const std::string& filename);
		sf::Texture& get(Textures::ID id);
		const sf::Texture& get(Textures::ID id) const;
	
	private:
		std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;

	};
	/*
	* *Example to use*
	* 
	*	TextureHolder text;
	*	text.load(Textures::Airplane, "path/to/file");
	*	sf::Sprite playerPlane;
	*	playerPlane.setTexture(text.get(Textures::AirPlane));
	*/

}
