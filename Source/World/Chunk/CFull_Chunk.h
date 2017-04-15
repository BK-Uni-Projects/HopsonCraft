#ifndef CFULL_CHUNK_H_INCLUDED
#define CFULL_CHUNK_H_INCLUDED

#include <vector>
#include <memory>

#include "CBlock.h"
#include "CPosition.h"
#include "CSection.h"

namespace Renderer
{
    class Master;
}

class World;
class Camera;

namespace Chunk
{
    enum class State
    {
        New,
        Populating,
        Populated,
    };


    class Map;

    class Full_Chunk
    {
        public:
            Full_Chunk() = default;
            Full_Chunk(World& world, Map& map, const Position& position, bool generate = true);

            void generateBlocks();

            void   setBlock(const Block::Position& position, CBlock block);
            CBlock getBlock(const Block::Position& position);

            void   qSetBlock(const Block::Position& position, CBlock block);
            CBlock qGetBlock(const Block::Position& position);
            const Position& getPosition() const;

            ///@TODO Move to .cpp file
            State getState() { return m_state; }

            /*
            int32_t getHighestBlock(int32_t x, int32_t z) const
            {
                return m_highestBlocks[x * CHUNK_SIZE + z];
            }
            */

            Section* getSection(int32_t index);

            uint32_t draw   (Renderer::Master& renderer, const Camera& camera);
            bool tryGen (const Camera& camera);

            void addSection();

        private:



            std::vector<std::unique_ptr<Section>>   m_chunkSections;
            //std::vector<int32_t>                    m_highestBlocks;

            std::vector<CPositioned_Block> m_positionedBlocks;

            World*      mp_world        = nullptr;
            Map*        mp_chunkMap     = nullptr;
            Position    m_position;
            int32_t     m_sectionCount  = 0;

            State m_state = State::New;
    };
}

#endif // CFULL_CHUNK_H_INCLUDED