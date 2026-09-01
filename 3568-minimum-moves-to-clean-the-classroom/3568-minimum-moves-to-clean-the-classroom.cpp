class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;

        // Give every litter a number
        int litterCount = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        // If there is no litter
        if (litterCount == 0)
            return 0;

        int totalMasks = 1 << litterCount;

        /*
            State:

            row
            col
            mask
            energy
        */

        // visited[row][col][mask][energy]
        int totalStates = m * n * totalMasks * (energy + 1);

        vector<char> visited(totalStates, false);

        auto getId = [&](int r, int c, int mask, int e) {
            return (((r * n + c) * totalMasks + mask)
                    * (energy + 1) + e);
        };

        queue<tuple<int, int, int, int>> q;

        // Starting state
        int startMask = 0;

        if (id[sr][sc] != -1) {
            startMask |= (1 << id[sr][sc]);
        }

        q.push({sr, sc, startMask, energy});

        visited[getId(sr, sc, startMask, energy)] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            // Process all states having same number of moves
            while (size--) {

                auto [r, c, mask, e] = q.front();
                q.pop();

                // All litter collected
                if (mask == totalMasks - 1) {
                    return moves;
                }

                // Try 4 directions
                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n) {
                        continue;
                    }

                    // Obstacle
                    if (classroom[nr][nc] == 'X') {
                        continue;
                    }

                    // Need energy to make a move
                    if (e == 0) {
                        continue;
                    }

                    // Moving costs 1 energy
                    int ne = e - 1;

                    // Collect litter
                    int nmask = mask;

                    if (id[nr][nc] != -1) {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Reset area
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    /*
                        If energy is 0 and we are not
                        standing on R, we cannot continue.
                    */
                    if (ne == 0 && classroom[nr][nc] != 'R') {
                        // We can still arrive here,
                        // but cannot move further.
                    }

                    int stateId = getId(nr, nc, nmask, ne);

                    if (!visited[stateId]) {

                        visited[stateId] = true;

                        q.push({
                            nr,
                            nc,
                            nmask,
                            ne
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};