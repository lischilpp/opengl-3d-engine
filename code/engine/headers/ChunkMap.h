#include <unordered_map>
#include <set>
#include <tuple>
#include <memory>

using namespace std;

struct KeyHash
{
    size_t operator()(const glm::ivec3& k)const
    {
        return std::hash<int>()(k.x) ^ std::hash<int>()(k.y) ^ std::hash<int>()(k.z);
    }
};
struct KeyEqual
{
    bool operator()(const glm::ivec3& a, const glm::ivec3& b)const
    {
        return a.x == b.x && a.y == b.y && a.z == b.z;
    }
};

typedef unordered_map<glm::ivec3, std::shared_ptr<Chunk>, KeyHash, KeyEqual> ChunkMap;

struct KeyCompare
{
    bool operator()(const glm::ivec3& a, const glm::ivec3& b)const
    {
         return a.x < b.x || (a.x == b.x && a.y < b.y) || (a.x == b.x && a.y == b.y && a.z < b.z);
    }
};

typedef set<glm::ivec3, KeyCompare> ChunkSet;
