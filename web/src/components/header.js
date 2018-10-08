import React from "react";
import { Link } from "gatsby";

import "./header.css";

const Header = ({ siteTitle }) => (
    <nav className="header">
        <ul>
            <li>
                <Link to="/">home</Link>
            </li>
            <li>
                <Link to="/help">help</Link>
            </li>
            <li>
                <a href="https://github.com/city41/ardynia">github</a>
            </li>
            <li>
                <Link to="/contact">contact</Link>
            </li>
        </ul>
    </nav>
);

export default Header;
