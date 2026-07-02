#pragma once

// Leader key (Danish characters æ ø å, see leader_end_user in keymap.c).
// No timeout on the leader key itself; 400ms allowed between sequence keys.
#define LEADER_NO_TIMEOUT
#define LEADER_TIMEOUT 400
#define LEADER_PER_KEY_TIMING
