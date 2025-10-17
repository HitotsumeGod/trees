-- constructs a binary tree from the top down, then outputs its total number of members
function mktree (parent, depth)
    if depth <= 0 then
        return 1
    end
    parent[1] = { }
    parent[2] = { }
    local sum = mktree(parent[1], depth - 1)
    sum = sum + mktree(parent[1], depth - 1)
    return sum
end
---------------------------------
local tree = { }
local layers = 4
print(mktree(tree, layers))
