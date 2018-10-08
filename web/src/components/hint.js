import React from "react";
import classnames from "classnames";

import "./hint.css";

class Hint extends React.Component {
    state = {
        revealed: false
    };

    render() {
        const { children } = this.props;
        const { revealed } = this.state;

        const classes = classnames("hint", {
            "hint--revealed": revealed
        });

        return (
            <div
                className={classes}
                onClick={() => this.setState({ revealed: true })}
            >
                {revealed ? children : "click to reveal"}
            </div>
        );
    }
}

export default Hint;
