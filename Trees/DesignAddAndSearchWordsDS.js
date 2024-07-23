var Node = function() {
    this.dict = {};
    this.endOfWord = false;
};

var WordDictionary = function() {
    this.first = new Node();
};

/** 
 * @param {string} word
 * @return {void}
 */
WordDictionary.prototype.addWord = function(word) {
    let current = this.first;
    for(let letter of word) {
        if (!(letter in current.dict)) {
            current.dict[letter] = new Node();
        }
        current = current.dict[letter];
    }
    current.endOfWord = true; // Mark the end of the word
};

/** 
 * @param {string} word
 * @return {boolean}
 */
WordDictionary.prototype.search = function(word) {
    let queue = [this.first];
    for (let letter of word) {
        let new_queue = [];
        if (letter === '.') {
            for (let node of queue) {
                for (let key in node.dict) {
                    new_queue.push(node.dict[key]);
                }
            }
        } else {
            for (let node of queue) {
                if (letter in node.dict) {
                    new_queue.push(node.dict[letter]);
                }
            }
        }
        if (new_queue.length === 0) return false;
        queue = new_queue;
    }

    for (let potential of queue) {
        if (potential.endOfWord) return true;
    }

    return false;
};