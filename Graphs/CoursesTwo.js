class Solution {
    findOrder(numCourses, prerequisites) {
        const coursePrereq = new Map();
        const ans = [];
        const toDfs = new Set();
        const hasBeenAdded = new Map();

        for (const pair of prerequisites) {
            if (!coursePrereq.has(pair[0])) {
                coursePrereq.set(pair[0], new Set());
            }
            coursePrereq.get(pair[0]).add(pair[1]);
        }

        for (let i = 0; i < numCourses; i++) {
            toDfs.add(i);
        }

        let loopFound = false;
        const seen = new Set();
        
        const dfs = (course) => {
            if (seen.has(course) || loopFound) {
                loopFound = true;
                return;
            }
            if (!coursePrereq.has(course) || coursePrereq.get(course).size === 0) {
                if (!hasBeenAdded.get(course)) {
                    ans.push(course);
                    hasBeenAdded.set(course, true);
                }
                toDfs.delete(course);
                return;
            }
            seen.add(course);
            for (const prereq of coursePrereq.get(course)) {
                dfs(prereq);
            }
            ans.push(course);
            hasBeenAdded.set(course, true);
            toDfs.delete(course);
            seen.delete(course);
        };

        while (toDfs.size > 0) {
            dfs(toDfs.values().next().value);
            if (loopFound) break;
        }

        return loopFound ? [] : ans;
    }
}

// Example usage:
const solution = new Solution();
const numCourses = 3;
const prerequisites = [[0,1],[0,2],[1,2]];
console.log(solution.findOrder(numCourses, prerequisites));