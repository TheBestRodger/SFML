#include "ResourceHolder.h"
#include <cassert>
namespace gm {
	template<typename Resource, typename Identifier>
	void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
	{
		std::unique_ptr<Resource> resource(new Resource());
		if (!resource->loadFromFile(filename))
			throw std::runtime_error("ResourceHolder::load - Faild to load" + filename);


		auto in = mResourceMap.insert(std::make_pair(id, std::move(resource)));
		assert(in.second);
	}
	template<typename Resource, typename Identifier>
	Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
	{
		auto found = mResourceMap.find(id);
		assert(found != mResourceMap.end());
		return *found->second;
	}
	template<typename Resource, typename Identifier>
	const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
	{
		auto found = mResourceMap.find(id);
		assert(found != mResourceMap.end());
		return *found->second;
	}
}